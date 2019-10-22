/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:27:50 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/18 16:10:13 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUFF_SIZE 30

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

typedef struct t_fillit
{
    char            *str;
    struct t_fillit *next;
    
}               s_fillit;


int     main(int ar, char **av);

#endif