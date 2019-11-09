
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:50:45 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/07 15:45:41 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_memdel(void **ap)
{
    if (*ap && ap)
    {
        free(*ap);
        *ap = NULL;
    }
}

 int      oversize(t_map *map, t_flist *list_tetramino)
 {
     int i;
     int x;
     int y;

     i = 0;
     x = 0;
     y = 0;
     x = list_tetramino->coordinate[i] + list_tetramino->x_start;
     y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
     while (i <= 6 && map->map[y][x] == '.')
     {
         i+= 2;
         x = list_tetramino->coordinate[i] + list_tetramino->x_start;
         y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
     }
//     printf("%s\n", map->map[0]);
//     printf("%s\n", map->map[1]);
//     printf("%s\n", map->map[2]);
//     printf("%s\n", map->map[3]);
//     printf("%s\n", map->map[4]);
     return (i);
 }

void    place_tetramino(t_flist *list_tetramino, t_map *map, char c)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (i <= 6)
    {
        x = list_tetramino->coordinate[i] + list_tetramino->x_start;
        y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
        //printf("x = %d y = %d\n", x, y);
        map->map[y][x] = c;
        i += 2;
    }
}

int     paste_tetramino(t_map *map, t_flist *list_tetramino, int size)
{
    if (list_tetramino == NULL)
        return (1);
    list_tetramino->x_start = 0;
    list_tetramino->y_start = 0;
    while (list_tetramino->coordinate[1] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[3] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[5] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[7] + list_tetramino->x_start < size)
    {
        while (list_tetramino->coordinate[0] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[2] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[4] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[6] + list_tetramino->x_start < size)
        {
            if (oversize(map, list_tetramino) == 8)
            {
                place_tetramino(list_tetramino, map, list_tetramino->c);
                printf("%s\n", map->map[0]);
                printf("%s\n", map->map[1]);
                printf("%s\n", map->map[2]);
                printf("%s\n", map->map[3]);
                printf("%s\n", map->map[4]);
                printf("%s\n", map->map[5]);
                printf("%s\n", map->map[6]);
//                printf("%s\n", map->map[7]);
//                printf("%s\n", map->map[8]);
//                printf("%s\n", map->map[9]);
//                printf("%s\n", map->map[10]);
                if (paste_tetramino(map, list_tetramino->next, size))
                    return (1);
                else
                    place_tetramino(list_tetramino, map, '.');
            }
            list_tetramino->x_start++;
        }
        list_tetramino->x_start = 0;
        list_tetramino->y_start++;
    }
    return (0);
}

void    free_map(t_map *map, int size)
{
     int i;

     i = 0;
     while (i < size)
     {
         ft_memdel((void*)&(map->map[i]));
         i++;
     }
     ft_memdel((void**)&(map->map));
     ft_memdel((void**)&(map));
}

void    filling_map(t_flist *list_tetramino)
{
    t_map *map;
    int size;
    int i;

    size = map_size(count_list(list_tetramino) * 4);
    map = new_map(size);
    while (paste_tetramino(map, list_tetramino, size) == 0)
    {
        free_map(map, size);
        size++;
        map = new_map((size));
    }
    printf("%s\n", map->map[i]);
    i = 0;
    while (i < size)
    {
        printf("%s\n", map->map[i]);
        //ft_putstr(map->map[i]);
        //ft_putchar('\n');
        i++;
    }
}

