/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetramino_rmaxima.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:47:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/03 15:11:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    coordinate(char **res)
{
    t_flist *list_tetramino;
    int i;
    int j;
    int count;

    list_tetramino = (t_flist*)malloc(sizeof(t_flist));

    j = 0;
    count = 0;
    while (j < 5)
    {
        i = 0;
        while (i < 4)
        {
            if (res[i][j] == '#' && count == 0)
            {
                list_tetramino->x = j + 1;
                list_tetramino->y = i + 1;
                count++;
            }
            if (res[i][j] == '#')
                count++;
            if (res[i][j] == '#' && count == 4)
            {
                list_tetramino->width = j - list_tetramino->x;
                list_tetramino->heigh = i - list_tetramino->y;
            }
            i++;
        }
        j++;
    }
    printf("x = %d y = %d width = %d heigh = %d\n", list_tetramino->x, list_tetramino->y, list_tetramino->width, list_tetramino->heigh);
}

void      array_tetramino(char *str)
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

//        printf("%d = %s", i, res[i]);
        i++;
    }
    coordinate(res);
}

