/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:47:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/05 18:50:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    push(t_flist **head, t_flist *list_coordinate)
{
    t_flist *tmp;

    tmp = (t_flist*)malloc(sizeof(t_flist));
    tmp->tetr = list_coordinate->tetr;
    tmp->x = list_coordinate->x;
    tmp->y = list_coordinate->y;
    tmp->width = list_coordinate->width;
    tmp->heigh = list_coordinate->heigh;
    tmp->next = (*head);
    (*head) = tmp;
    map(tmp);
}

void    coordinate(char **res, int heigh, int y)
{
    t_flist *list_tetramino;
    t_flist *head;
    int i;
    int j;
    int count;

    list_tetramino = (t_flist*)malloc(sizeof(t_flist));

    j = 0;
    count = 0;
    head = NULL;
    list_tetramino->tetr = res;
    list_tetramino->y = y;
    list_tetramino->heigh = heigh;
    while (j < 5)
    {
        i = 0;
        while (i < 4)
        {
            if (res[i][j] == '#' && count == 0)
            {
                list_tetramino->x = j;
            }
            if (res[i][j] == '#')
                count++;
            if (res[i][j] == '#' && count == 4)
            {
                list_tetramino->width = j + 1 - list_tetramino->x;
            }
            i++;
        }
        j++;
    }
    //printf("tetr = %s x = %d y = %d width = %d heigh = %d\n", list_tetramino->tetr[0], list_tetramino->x, list_tetramino->y, list_tetramino->width, list_tetramino->heigh);
   push(&head, list_tetramino);
}

void      array_tetramino(char *str)
{
    char **res;
    int i;
    int j;
    int y1;
    int y2;
    int count;

    if (!(res = (char**)malloc(sizeof(char*) * 4)))
        printf("Error");
    i = 0;
    count = 0;
    while (i < 4)
    {
        res[i] = (char*)malloc(sizeof(char) * 4);
        j = 0;
        while (j < 5)
        {
            res[i][j] = str[i * 5 + j];
            if (res[i][j] == '#' && count == 0)
            {
                y1 = i;
            }
            if (res[i][j] == '#')
                count++;
            if (res[i][j] == '#' && count == 4)
                y2 = i;
            j++;
        }
        printf("%d = %s", i, res[i]);
        i++;
    }
    coordinate(res, y2 + 1 - y1, y1);
}

