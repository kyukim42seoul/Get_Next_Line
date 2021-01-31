/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:51 by kyukim            #+#    #+#             */
/*   Updated: 2021/01/31 18:17:20 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int				line_len;
	int				read_size;
	char			*buf;
	char			**storage; //next_point 랑 기능 통합 가능
	char			**checkpoint;

	read_size = 0;
	storage = line;
	checkpoint = storage;
	buf = (char *)malloc(sizeof(char) * 10 + 1);
	storage = (char **)malloc(sizeof(char *) * 5);
	*storage = (char *)malloc(sizeof(char) * 100 + 1);
	buf[10] = '\0';
	while ((line_len = read(fd, buf, 3)))
	{
		read_size += line_len;
		if (check_next_line(buf))
		{
//			merge_line(storage, buf);
			(storage)++;
			return (1);
		}
//		else
//			merge_line(storage, buf);
	}
	return (read_size);
}
