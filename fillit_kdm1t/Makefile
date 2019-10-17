# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 16:14:29 by mwilbur           #+#    #+#              #
#    Updated: 2019/10/17 16:46:55 by mwilbur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRCS=./srcs/fillit.c
INCLUDES=./includes/fillit.h
OBJECTS=./srcs/fillit.o
FLAGS=-Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRCS)
	gcc -I $(INCLUDES) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all



