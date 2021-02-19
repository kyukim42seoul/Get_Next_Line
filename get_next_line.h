/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:59 by kyukim            #+#    #+#             */
/*   Updated: 2021/02/19 12:10:39 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		get_next_line(int fd, char **line);
int		gnl_strlen(char *str);
char	*merge_line(char *dst, char *src);
char	*check_next_line(char *buf);
char	*gnl_strcut(char *src);

#endif
