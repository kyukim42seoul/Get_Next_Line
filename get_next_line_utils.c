/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:57 by kyukim            #+#    #+#             */
/*   Updated: 2021/02/08 23:27:37 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strcut(char *src)
{
	char	*new_line;
	char	*temp;
	char	*temp2;
	int		len;

	len = 0;
	temp = src;
	if (!src)
		return (0);
	while (*temp != '\n' && *temp)
	{
		temp++;
		len++;
	}
	new_line = (char *)malloc(sizeof(char) * len + 1);
	if (!new_line)
		return (NULL);
	temp2 = new_line;
	while (len--)
		*temp2++ = *src++;
	*temp2 = '\0';
	return (new_line);
}

int		gnl_strlen(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

char	*merge_line(char *dst, char *src)
{
	char		*new_line;
	char		*temp;
	int			count;

	count = gnl_strlen(src);
	if (!dst && !src)
		return (NULL);
	new_line = (char *)malloc(sizeof(char) * (gnl_strlen(dst) + gnl_strlen(src)) + 1);
	if (!new_line)
		return (NULL);
	temp = new_line;
	if (dst)
		while (*dst)
			*temp++ = *dst++;
	if (src)
		while (count--)
			*temp++ = *src++;
	*temp = '\0';
	return (new_line);
}

char	*check_next_line(char *storage)
{
	char	*after_next_line;

	after_next_line = storage;
	if (!storage)
		return (0);
	while (*after_next_line)
	{
		if (*after_next_line == '\n')
		{
			after_next_line++;
			return (after_next_line);
		}
		else
			after_next_line++;
	}
	return (0);
}
