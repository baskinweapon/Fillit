/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:15:02 by mwilbur           #+#    #+#             */
/*   Updated: 2019/11/03 12:28:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
#include <stdio.h>

typedef struct		s_flist {
    char 			**tetr;
    int             x;
    int             y;
    int             width;
    int             heigh;
    struct s_flist	*next;
}					t_flist;

int		check_tetramino(char *str);
int		check_input(char *str);
int		checks(char *str, int fd, int ret);
t_flist	*ft_flstnew(char *str, size_t len);
t_flist	*ft_flstclear(t_flist *lst);
void	ft_flstdisplay(t_flist *lst);
int		validate(char *str, int fd);

//list tetramino
void    array_tetramino(char *str);

#endif
