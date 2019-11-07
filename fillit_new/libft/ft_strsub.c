/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:26:24 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/16 18:13:28 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dst;
	char *src;

	dst = ft_strnew(len);
	src = (char*)s;
	if (!dst || !src)
		return (NULL);
	dst = ft_strncpy(dst, &s[start], len);
	return (dst);
}
