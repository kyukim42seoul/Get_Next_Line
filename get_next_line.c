/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:51 by kyukim            #+#    #+#             */
/*   Updated: 2021/02/01 22:35:19 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int				line_len;
	int				read_size;
	char			*buf;
	static char		*storage;

	read_size = 0;
	buf = (char *)malloc(sizeof(char) * 10 + 1);
	buf[10] = '\0';
	while ((line_len = read(fd, buf, 3)))
	{
		read_size += line_len;
		if (check_next_line(buf))
		{
			storage = merge_line(storage, buf);
			*line = storage;
			return (1);
		}
		else
			storage = merge_line(storage, buf);
	}
	free(buf);
	return (read_size);
}
