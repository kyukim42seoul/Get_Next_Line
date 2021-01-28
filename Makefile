# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyukim <kyukim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 01:26:48 by kyukim            #+#    #+#              #
#    Updated: 2021/01/29 01:28:44 by kyukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS =	get_next_line.o \
			get_next_line_utils.o \

all : $(NAME)

$(NAME) : $(OBJECTS) libft.h
	ar -rc $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(NAME) $(OBJECTS_B)
	ar -rc $(NAME) $(OBJECTS_B)

.PHONY: bonus all clean fclean re