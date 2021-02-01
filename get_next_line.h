/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:59 by kyukim            #+#    #+#             */
/*   Updated: 2021/02/01 21:22:31 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line);
int		gnl_strlen(char *str);
char	*merge_line(char *dst, char *src);
//char	*gnl_strcpy(char *dst, char *src);
int		check_next_line(char *buf);

#endif
