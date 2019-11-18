
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
#include <stdio.h>

void	ft_memdel(void **ap)
{
    if (ap != NULL)
    {
        free(*ap);
        *ap = NULL;
    }
}

void    free_map(t_map *map, int map_size)
{
    int i;

    i = 0;
    while (i < map_size)
    {
        ft_memdel((void**)&(map->map[i]));
        i++;
    }
    ft_memdel((void**)&(map->map));
    ft_memdel((void**)&map);


}

int     over_size(t_flist *list_tetramino, t_map *map)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    x = list_tetramino->coordinate[i] + list_tetramino->x_start;
    y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
    while (i < 8 && map->map[y][x] == '.')
    {
        i += 2;
        x = list_tetramino->coordinate[i] + list_tetramino->x_start;
        y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
    }
    return (i);
}

//есть карта и есть координаты тетрамину, нужно помещать в карту все тетрамины
void    place(t_flist *list_tetramino, t_map *map, char c)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (i < 8)
    {
        x = list_tetramino->coordinate[i] + list_tetramino->x_start;
        y = list_tetramino->coordinate[i + 1] + list_tetramino->y_start;
        map->map[y][x] = c;
        i += 2;
    }
}

int     ft_x(t_flist *list_tetramino, int map_size)
{
    return (list_tetramino->coordinate[0] + list_tetramino->x_start < map_size &&
            list_tetramino->coordinate[2] + list_tetramino->x_start < map_size &&
            list_tetramino->coordinate[4] + list_tetramino->x_start < map_size &&
            list_tetramino->coordinate[6] + list_tetramino->x_start < map_size);

}

int     ft_y(t_flist *list_tetramino, int map_size)
{
        return (list_tetramino->coordinate[1] + list_tetramino->y_start < map_size &&
            list_tetramino->coordinate[3] + list_tetramino->y_start < map_size &&
            list_tetramino->coordinate[5] + list_tetramino->y_start < map_size &&
            list_tetramino->coordinate[7] + list_tetramino->y_start < map_size);
}

int     paste(t_map *map, t_flist *list_tetramino, int map_size)
{
    if (!list_tetramino)
        return (1);
    list_tetramino->x_start = 0;
    list_tetramino->y_start = 0;
    while (ft_y(list_tetramino, map_size))
    {
        while (ft_x(list_tetramino, map_size))
        {
            if (over_size(list_tetramino, map) == 8)
            {
                place(list_tetramino, map, list_tetramino->c);
                if  (paste(map, list_tetramino->next, map_size))
                    return (1);
                else
                    place(list_tetramino, map, '.');
            }
            list_tetramino->x_start++;
        }
        list_tetramino->x_start = 0;
        list_tetramino->y_start++;
    }
    return (0);
}

void    filling_map(t_flist *list_tetramino)
{
    t_map *map;
    int size;

    size = map_size(count_list(list_tetramino) * 4);
    map = new_map(size);
    while (!(paste(map, list_tetramino, size)))
    {
        free_map(map, size);
        size++;
        map = new_map(size);
    }
    int i = 0;
    while (i < size)
    {
        printf("%s", map->map[i]);
        printf("\n");
        i++;
    }
}

