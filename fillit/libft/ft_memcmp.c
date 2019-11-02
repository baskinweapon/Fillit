/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:56:54 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/16 18:09:11 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	i = 0;
	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	if (n != 0)
	{
		while (first[i] == second[i] && i < n - 1)
			i++;
		return (first[i] - second[i]);
	}
	return (0);
}
