/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:20:32 by user              #+#    #+#             */
/*   Updated: 2019/12/08 17:29:59 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		over_size(t_flist *list_tetramino, t_map *map)
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

void	free_map(t_map *map, int map_size)
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
