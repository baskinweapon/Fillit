/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetramino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:47:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/30 14:04:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    list_tetramino(char **masstr, int x, int y, int width, int height)
{
    t_fillit    *res;
    

    //это тоже бред, нужно переделать
    res = (t_fillit*)malloc(sizeof(t_fillit));
    res->str = masstr;
    res->x = x + 1;
    res->y = y + 1;
    res->width = width + 1;
    res->height = height + 1;
    // printf("%s", res->str[0]);
    // printf("%s", res->str[1]);
    // printf("%s", res->str[2]);
    // printf("%s", res->str[3]);
    // printf("%d %d\n", res->x, res->width);
    // printf("%d %d\n", res->y, res->height);
    // printf("%d\n", (res->width - res->x) * (res->height - res->y));
}



void      massive_tetramino(char *str)
{
    char **res;
    int i;
    int j;
    int x;
    int y;
    int width;
    int height;
    int count;

    count = 0;
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
            //тупой алгоритм
            if (res[i][j] == '#')
                count++;
            if (res[i][j] == '#' && count == 1)
            {
                x = j;
                y = i;
                printf("%d %d\n", x, y);
            }
            if (res[i][j] == '#' && count == 4)
            {
                width = j;
                height = i;
                printf("%d %d\n", width, height);
            }
            //надо подумать, как найти корректные координаты для вычесления площади
            j++;
        }
        i++;
    }
    list_tetramino(res, x, y, width, height);
}

