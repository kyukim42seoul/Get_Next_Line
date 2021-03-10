/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:51 by kyukim            #+#    #+#             */
/*   Updated: 2021/03/10 12:01:11 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	set_backup(int fd, char *buf, char **backup, char **is_next_line)
{
	char		*temp;
	int			read_len;

	temp = 0;
	read_len = 0;
	while (!check_next_line(*backup, is_next_line))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
			return (-1);
		else if (read_len == 0)
			break ;
		else
		{
			buf[read_len] = '\0';
			temp = merge_line(*backup, buf, read_len);
			if (!temp)
				return (-1);
			free(*backup);
			*backup = temp;
		}
	}
	return (1);
}

int	set_line_by_cases(char **line, char *is_next_line, char **backup)
{
	char		*temp;

	temp = 0;
	if (is_next_line)
	{
		*line = gnl_strcut(*backup, (is_next_line - *backup));
		if (!*line)
			return (-1);
		temp = gnl_strcut((is_next_line + 1), gnl_strlen(is_next_line));
		if (!temp)
			return (-1);
		free(*backup);
		*backup = temp;
		return (1);
	}
	else
	{
		*line = gnl_strcut(*backup, gnl_strlen(*backup));
		if (!*line)
			return (-1);
		free(*backup);
		*backup = 0;
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup[OPEN_MAX];
	char		*is_next_line;
	int			result;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	is_next_line = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	if (set_backup(fd, buf, &backup[fd], &is_next_line) < 0)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	result = set_line_by_cases(line, is_next_line, &backup[fd]);
	return (result);
}
