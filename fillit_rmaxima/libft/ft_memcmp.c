/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:49:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/16 15:04:31 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i <= n)
	{
		i++;
		if (i == n || (str1 == '\0' && str2 == '\0'))
			return (0);
	}
	return (str1[i] - str2[i]);
}
