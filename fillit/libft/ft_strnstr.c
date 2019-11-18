/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:31:54 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/19 16:40:05 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	size_t	lenm;
	char	*res;

	i = 0;
	lenm = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < (len - lenm + 1))
	{
		j = i;
		tmp = 0;
		res = ((char*)&haystack[j]);
		while (haystack[j] == needle[tmp++] && j < len)
		{
			j++;
			if (!needle[tmp])
				return (res);
		}
		i++;
	}
	return (0);
}
