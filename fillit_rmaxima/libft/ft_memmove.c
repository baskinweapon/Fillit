/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:54:56 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/16 14:49:13 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (str1 == str2)
		return (dst);
	if (str2 < str1)
	{
		str2 = (unsigned char*)src + len - 1;
		str1 = dst + len - 1;
		while (len--)
			*str1-- = *str2--;
	}
	else
	{
		while (len--)
			*str1++ = *str2++;
	}
	return (dst);
}
