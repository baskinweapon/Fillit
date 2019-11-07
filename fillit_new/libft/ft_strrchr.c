/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:02:04 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/08 18:15:26 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *lp;

	lp = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			lp = (char*)s;
		s++;
	}
	if (lp != NULL)
		return ((char*)lp);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
