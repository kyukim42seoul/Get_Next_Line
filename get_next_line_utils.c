/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:57 by kyukim            #+#    #+#             */
/*   Updated: 2021/01/29 03:07:07 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		gnl_strlen(const char *str)
{
	int		len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	merge_line(char **dst, const char *src)
{
	char			*new_line;
	static char		*temp;

	if (!(dst || src))
		return ;
	new_line = (char *)malloc(sizeof(char) * (gnl_strlen(*dst) + gnl_strlen(src)) + 1);
	if (!new_line)
		return ;
	temp = new_line;
	while ((**dst))
		*temp++ = (**dst)++;
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
}

int		check_next_line(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
		{
			*(++buf) = '\0';
			return (1);
		}
		else
			return (0);
		buf++;
	}
	return (-1);
}