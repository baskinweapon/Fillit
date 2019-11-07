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

// void      oversize(t_map *map)
// {

// }

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
    list_tetramino->x_start++;
    list_tetramino->y_start++;
    printf("%s\n", map->map[0]);
    printf("%s\n", map->map[1]);
    printf("%s\n", map->map[2]);
    printf("%s\n", map->map[3]);
    printf("%s\n", map->map[4]);
    printf("%s\n", map->map[5]);
    printf("%s\n", map->map[6]);
}

int     paste_tetramino(t_map *map, t_flist *list_tetramino, int size)
{
    

    
    while (list_tetramino->coordinate[0] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[2] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[4] + list_tetramino->x_start < size && \
        list_tetramino->coordinate[6] + list_tetramino->x_start < size)
    {
        place_tetramino(list_tetramino, map, list_tetramino->c);
        list_tetramino = list_tetramino->next; 
    }
     
    
    return (0);
}

t_map   *filling_map(t_flist *list_tetramino)
{
    t_map *map;
    int i;
    int size;

    size = map_size(count_list(list_tetramino) * 4);
    map = new_map(size);
    i = 0;
    while (i < 10)
    {
        paste_tetramino(map, list_tetramino, size);
        //place_tetramino(list_tetramino, map, list_tetramino->c);
        i++;
    }
    return (NULL);
}
