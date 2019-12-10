# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 17:25:35 by mwilbur           #+#    #+#              #
#    Updated: 2019/12/10 15:15:46 by mwilbur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ./srcs/*.c
OBJS = ./srcs/*.o
INCLUDES = ./includes/fillit.h
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INCLUDES) -L. libft/libft.a

clean:
		rm -f $(OBJS);
		make -C $(LIBFT) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
