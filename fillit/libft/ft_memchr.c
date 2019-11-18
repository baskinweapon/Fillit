/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:38:50 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/16 14:47:56 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;

	str1 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (str1[i] == ((unsigned char)c))
			return ((unsigned char*)s + i);
		i++;
	}
	return (NULL);
}
