/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:51:24 by rmaxima           #+#    #+#             */
/*   Updated: 2019/12/03 16:14:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		map_size(int ret)
{
	int size;

	size = 2;
	while (size * size < ret)
		size++;
	return (size);
}

int		count_list(t_flist *list)
{
	int counter;

	counter = 0;
	while (list)
	{
		list = list->next;
		counter++;
	}
	return (counter);
}

t_map	*new_map(int size)
{
	t_map	*ptr;
	int		i;

	ptr = (t_map*)malloc(sizeof(t_map));//check
	ptr->map = (char**)malloc(sizeof(char*) * size);//check
	i = 0;
	while (i < size)
	{
		ptr->map[i] = (char*)malloc(sizeof(char) * (size + 1));//check
		ft_memset(ptr->map[i], '.', size);
		i++;
	}
	return (ptr);
}

void	print_map(int size, t_map *map)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->map[i]);
		ft_putstr("\n");
		i++;
	}
}