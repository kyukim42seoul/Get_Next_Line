/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:51 by kyukim            #+#    #+#             */
/*   Updated: 2021/02/25 16:21:18 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int				read_len;
	char			*buf;
	static char		*backup;
	char			*is_next_line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)	// fd 가 0 부터 시작한다.
		return (-1);
	read_len = 0;
	is_next_line = 0;
	temp = 0;
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (!check_next_line(backup, &is_next_line))	//'\n' 의 유\무에 따라 1\0 을 반환하고 그 위치를 is_next_line 에 담아서 나옴
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
			return (-1);
		else if (read_len == 0)	// 개행이 없고, read_len 이 0 인 상황 = 마지막 문장
			break ;
		else	// 개행이 없고, read_len 이 있는 상황 = 아직 읽어들일 게 남음.
		{
			buf[read_len] = '\0';
			temp = merge_line(backup, buf, read_len);
			if (backup)
				free(backup);
			backup = temp;
		}
	}
	free(buf);
	if (is_next_line)
	{
		*line = gnl_strcut(backup, (is_next_line - backup));
		backup = gnl_strcut((is_next_line + 1), gnl_strlen(is_next_line));
		free(temp);
		return (1);
	}
	else
	{
		*line = gnl_strcut(backup, gnl_strlen(backup));
		free(backup);
		backup = 0;
		return (0);
	}
}
