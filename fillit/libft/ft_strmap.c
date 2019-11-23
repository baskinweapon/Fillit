/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:12:22 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/13 18:11:11 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*src;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	src = (char*)s;
	result = ft_memalloc((size_t)ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (src[i])
	{
		result[i] = f(src[i]);
		i++;
	}
	return (result);
}
