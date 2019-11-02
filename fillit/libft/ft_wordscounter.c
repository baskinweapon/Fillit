/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscounter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:00:02 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/17 17:13:52 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordscounter(char const *str, char delimiter)
{
	int i;
	int flag;
	int counter;

	i = 0;
	flag = 0;
	counter = 0;
	if (!str || !delimiter)
		return (0);
	while (str[i] == delimiter)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!flag && str[i] != delimiter)
		{
			flag = 1;
			counter++;
		}
		else if (str[i] == delimiter && flag)
			flag = 0;
		i++;
	}
	return (counter);
}
