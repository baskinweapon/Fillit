/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:27:50 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/30 14:03:10 by alex             ###   ########.fr       */
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

// typedef struct s_coordinate
// {
//     int     x1;
//     int     y1;
//     int     x2;
//     int     y2;
//     struct s_coordinate *nest;
// }               t_coordinate;

typedef struct s_fillit
{
    char            **str;
    int             x;
    int             y;
    int             width;
    int             height;
    struct s_fillit *next;
    
}               t_fillit;

// validate.c
int     tetramino(char *str);
int     validate(char *str);

//list tetramino
void    list_tetramino(char **str, int x, int y, int weight, int height);
void    massive_tetramino(char *str);

int     main(int ar, char **av);

#endif