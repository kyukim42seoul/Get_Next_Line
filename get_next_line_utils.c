/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:57 by kyukim            #+#    #+#             */
/*   Updated: 2021/01/29 01:26:57 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_strlen(const char *str)
{
	int		len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*merge_line(const char **dst, const char *src)
{
	char	*new_line;
	char	*temp;

	if (!*dst || *src)
		return (NULL);
	new_line = (char *)malloc(sizeof(char) * (strlen(dst) + strlen(src)) + 1);
	if (!new_line)
		return (NULL);
	temp = new_line;
	while (*dst)
		*temp++ = *dst++;
	while (*src)
		*temp++ = *src++;
	temp = '\0';
	return (new_line);
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
}