/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:51 by kyukim            #+#    #+#             */
/*   Updated: 2021/01/29 01:26:52 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int			line_len;
	int			read_size;
	char		*buf;
	char		*storage; //next_point 랑 기능 통합 가능
	static void	*next_point;

	read_size = 0;
	buf = (char *)malloc(sizeof(char) * 10 + 1);
	storage = (char *)malloc(sizeof(char) * 100 + 1);
	buf[10] = '\0';
	while ((line_len = read(1, buf, 1)))
	{
		read_size += line_len;
		if (check_next_line(buf))
		{
			merge_line(line, buf);
			printf("1 : %s", *line);
			(line)++;
			return (1);
		}
		else
		{
			merge_line(line, buf);
			printf("2 : %s", *line);
		}
	}
	return (read_size);
}
