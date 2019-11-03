/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:08:40 by mwilbur           #+#    #+#             */
/*   Updated: 2019/11/02 18:49:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h> //Удалить
#include <string.h> //delete

t_flist *init(t_flist *lst, char arr[])
{
	lst = (t_flist*)malloc(sizeof(t_flist));
	if (!lst)
		return (0);
	ft_memcpy(lst->tetr, arr, ft_strlen(arr));
	lst->next = NULL;
	return (lst);
}

t_flist *add_element(t_flist *lst, char arr[])
{
	t_flist *cur;
	t_flist *tmp;

	cur = (t_flist*)malloc(sizeof(t_flist));
	if (!cur)
		return (NULL);
	if (!lst)
		cur = init(lst, arr);
	else
	{
		tmp = lst;
		ft_memcpy(cur->tetr, arr, ft_strlen(arr));
		cur->next = lst;
	}
	return (cur);
}

void	ft_flstdisplay(t_flist *lst) // Удалить
{
	t_flist *cur;

	cur = lst;
	while (cur->next)
	{
		printf("%s\n", cur->tetr);
		cur = cur->next;
	}
	printf("%s", cur->tetr);
}

// int		main(void)
// {
// 	t_flist *lst = NULL;
// 	t_flist *head = lst;
// 	char first[21] = "..#.\n..#.\n....\n....\n\n";
// 	char second[21] = "....\n###.\n....\n.#..\n\n";
// 	char third[21] = "##.\n..##\n..#.\n...#\n\n";

// 	lst = add_element(lst, first);
// 	// ft_flstdisplay(lst);
// 	lst = add_element(lst, second);
// 	lst = add_element(lst, third);
// 	ft_flstdisplay(head);
// 	return (0);
// }
