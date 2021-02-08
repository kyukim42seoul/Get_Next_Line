/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:51 by kyukim            #+#    #+#             */
/*   Updated: 2021/02/08 23:28:18 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// fd 에 문제있을 경우
// BUFFER_SIZE 가 0 또는 0 보다 작을 때
// **line 이 NULL 일 때
// 다 끝나고 storage 처리

int	get_next_line(int fd, char **line)
{
	int				read_result;
	char			*buf;
	static char		*storage;
	char			*rest;

	if ((fd <= 0) || (BUFFER_SIZE <= 0) || (line == 0))
		return (-1);
	rest = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((read_result = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_result] = '\0';
		storage = merge_line(storage, buf);
		if (check_next_line(storage))
			break ;
	}
	if (read_result < 0)
		return (-1);
	if ((rest = check_next_line(storage)) && storage)
	{
		*line = gnl_strcut(storage);
		storage = rest;
		return (1);
	}
	else
		*line = gnl_strcut(storage);
	return (0);
}
