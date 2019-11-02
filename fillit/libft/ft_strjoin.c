/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:25:20 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/17 14:29:02 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	str = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = ft_strnew(len);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strlcat(str, s2, len);
		}
	}
	return (str);
}
