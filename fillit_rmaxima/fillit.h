/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:27:50 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/28 16:09:42 by user             ###   ########.fr       */
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
int     validate(char *str);

//list tetramino
void    list_tetramino(char **str);
void    massive_tetramino(char *str);

int     main(int ar, char **av);

#endif