/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:26:59 by kyukim            #+#    #+#             */
/*   Updated: 2021/03/05 20:33:44 by kyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

int		get_next_line(int fd, char **line);
int		gnl_strlen(char *str);
int		check_next_line(char *backup, char **is_next_line);
char	*merge_line(char *backup, char *buf, int read_len);
char	*gnl_strcut(char *backup, int len);
int		set_backup(int fd, char *buf, char **backup, char **is_next_line);
int		set_line_by_cases(char **line, char *is_next_line, char **backup);

#endif
