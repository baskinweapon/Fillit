/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:43:51 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/19 21:02:41 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;
	int		i;

	if (!lst || !f)
		return (NULL);
	i = 0;
	new_elem = f(lst);
	new_elem->next = ft_lstmap(lst->next, f);
	return (new_elem);
}
