/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:49:32 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/17 15:26:26 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*src;
	char	*end;

	if (!s)
		return (NULL);
	src = (char*)s;
	while (*src == ' ' || *src == '\n' || *src == '\t')
		src++;
	if (*src == '\0')
		return (ft_strnew(0));
	end = &src[ft_strlen(src) - 1];
	while (*end == ' ' || *end == '\n' || *end == '\t')
		end--;
	return (ft_strsub(src, 0, end - src + 1));
}
