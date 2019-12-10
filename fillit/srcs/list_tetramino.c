/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetramino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:51:03 by rmaxima           #+#    #+#             */
/*   Updated: 2019/12/08 16:03:44 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_flist		*zero_coordinate(t_flist *ptr)
{
	while (ptr->coordinate[0] != 0 && ptr->coordinate[2] != 0
			&& ptr->coordinate[4] != 0 && ptr->coordinate[6] != 0)
	{
		ptr->coordinate[0] = ptr->coordinate[0] - 1;
		ptr->coordinate[2] = ptr->coordinate[2] - 1;
		ptr->coordinate[4] = ptr->coordinate[4] - 1;
		ptr->coordinate[6] = ptr->coordinate[6] - 1;
	}
	while (ptr->coordinate[1] != 0 && ptr->coordinate[3] != 0
			&& ptr->coordinate[5] != 0 && ptr->coordinate[7] != 0)
	{
		ptr->coordinate[1] = ptr->coordinate[1] - 1;
		ptr->coordinate[3] = ptr->coordinate[3] - 1;
		ptr->coordinate[5] = ptr->coordinate[5] - 1;
		ptr->coordinate[7] = ptr->coordinate[7] - 1;
	}
	return (ptr);
}

t_flist		*make_list(char *str, int c)
{
	t_flist	*ptr;
	int		x;
	int		y;
	int		i;

	if (!(ptr = (t_flist*)malloc(sizeof(t_flist))))
		return (NULL);
	x = 0;
	y = 1;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			ptr->coordinate[x] = (i >= 5) ? (i % 5) : i;
			ptr->coordinate[y] = i / 5;
			x += 2;
			y += 2;
		}
		ptr->x_start = 0;
		ptr->y_start = 0;
		ptr->c = c;
		i++;
	}
	return (zero_coordinate(ptr));
}

t_flist		*add_list(char *str, int ret)
{
	t_flist	*begin;
	t_flist	*next;
	int		i;
	int		c;

	c = 'A';
	i = 0;
	while (i < ret)
	{
		if (c == 'A')
		{
			begin = make_list(str + i, c);
			next = begin;
		}
		else
		{
			next->next = make_list(str + i, c);
			next = next->next;
		}
		c++;
		i += 21;
	}
	next->next = NULL;
	return (begin);
}
