/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:57 by kyukim            #+#    #+#             */
/*   Updated: 2021/08/20 10:15:34 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strcut(char *backup, int len)
{
	char	*new_line;
	char	*temp;

	if (!backup)
	{
		new_line = (char *)malloc(sizeof(char));
		new_line[0] = '\0';
		return (new_line);
	}
	new_line = (char *)malloc(sizeof(char) * len + 1);
	if (!new_line)
		return (NULL);
	temp = new_line;
	while (len--)
		*temp++ = *backup++;
	*temp = '\0';
	return (new_line);
}

int	gnl_strlen(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

char	*merge_line(char *backup, char *buf, int read_len)
{
	char		*new_line;
	char		*temp;

	if (!(backup || buf))
		return (NULL);
	new_line = (char *)malloc(sizeof(char)
			* (gnl_strlen(backup) + read_len + 1));
	if (!new_line)
		return (NULL);
	temp = new_line;
	if (backup)
		while (*backup)
			*temp++ = *backup++;
	if (buf)
		while (*buf)
			*temp++ = *buf++;
	*temp = '\0';
	return (new_line);
}

int	check_next_line(char *backup, char **is_next_line)
{
	if (!backup)
		return (0);
	while (*backup)
	{
		if (*backup == '\n')
		{
			*is_next_line = backup;
			return (1);
		}
		else
			backup++;
	}
	return (0);
}
