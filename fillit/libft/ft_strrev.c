/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:15:23 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/19 17:18:48 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t		i;
	size_t		len;
	char		dst;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 > i)
	{
		dst = str[i];
		str[i] = str[len - 1];
		str[len - 1] = dst;
		len--;
		i++;
	}
	return (str);
}
