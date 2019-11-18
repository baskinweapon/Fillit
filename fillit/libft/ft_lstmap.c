/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:27:03 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/19 15:38:06 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cont;
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	cont = f(lst);
	if (!(res = ft_lstnew(cont->content, cont->content_size)))
		return (NULL);
	lst = lst->next;
	tmp = res;
	while (lst)
	{
		cont = f(lst);
		if (!(res->next = ft_lstnew(cont->content, cont->content_size)))
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (tmp);
}
