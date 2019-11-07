/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:47:01 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/17 14:35:46 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		k = i;
		result = (char*)&haystack[i];
		while (haystack[k] && needle[j] == haystack[k++])
			j++;
		if (!needle[j])
			return (result);
		i++;
	}
	return (NULL);
}
