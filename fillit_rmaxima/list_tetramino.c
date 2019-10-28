/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetramino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:47:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/28 16:31:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    list_tetramino(char **masstr)
{
    t_fillit    **res;
    int i;
}

void      massive_tetramino(char *str)
{
    char **res;
    int i;
    int j;

    if (!(res = (char**)malloc(sizeof(char*) * 4)))
        printf("Error");
    i = 0;
    while (i < 4)
    {
        res[i] = (char*)malloc(sizeof(char) * 4);
        j = 0;
        while (j < 5)
        {
            res[i][j] = str[i * 5 + j];
            j++;
        }
        printf("%s", res[i]);
        i++;
    }
    // list_tetramino(res);
}

