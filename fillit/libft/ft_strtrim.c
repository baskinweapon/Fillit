/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:39:43 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/18 13:06:08 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	size;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s);
	while ((i < j) && (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t'))
		j--;
	if (i == j)
		return (ft_strnew(1));
	size = j - i;
	return (ft_strsub(s, i, size));
}
