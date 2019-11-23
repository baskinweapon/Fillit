/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:01:04 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/09 17:29:03 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*first;
	unsigned char	*second;

	i = 0;
	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	if ((!first[i] && second[i]) || (first[i] && !second[i]))
		return (first[i] - second[i]);
	return (0);
}
