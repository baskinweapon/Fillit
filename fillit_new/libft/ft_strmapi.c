/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:08:18 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/13 18:11:44 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;
	char	*src;

	if (!s)
		return (NULL);
	i = 0;
	src = (char*)s;
	result = ft_memalloc((size_t)ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (src[i])
	{
		result[i] = f(i, src[i]);
		i++;
	}
	return (result);
}
