/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:59 by kyukim            #+#    #+#             */
/*   Updated: 2021/01/29 02:34:04 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line);
int		gnl_strlen(const char *str);
void	merge_line(char **dst, const char *src);
int		check_next_line(char *buf);

#endif
