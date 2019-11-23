/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:57:47 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/16 18:15:08 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*result;

	len = ft_nlen(n);
	nb = n;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	result[len--] = '\0';
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		result[len--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (result);
}
