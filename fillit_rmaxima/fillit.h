/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:27:50 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/26 17:28:48 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUFF_SIZE 21

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
# include "libft/libft.h"

// typedef struct t_fillit
// {
//             char **av;
//     struct t_fillit *next;
// };              s_fillit

typedef struct s_fillit
{
    char            **str;
    int             x;
    int             y;
    struct s_fillit *next;
    
}               t_fillit;

// validate.c
int     tetramino(char *str);
int     validate(char *str, int fd);

//list tetramino
void    list_tetramino(char *str);

int     main(int ar, char **av);

#endif