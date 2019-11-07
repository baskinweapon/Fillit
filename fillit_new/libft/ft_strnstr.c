/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:39:57 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/19 21:36:15 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len_s2;
	char	*result;

	i = 0;
	if (!s2[i])
		return ((char*)s1);
	len_s2 = ft_strlen(s2);
	while (s1[i] && i < (len - len_s2 + 1))
	{
		j = i;
		k = 0;
		result = ((char*)&s1[j]);
		while (s1[j] == s2[k++] && j < len)
		{
			j++;
			if (!s2[k])
				return (result);
		}
		i++;
	}
	return (NULL);
}
