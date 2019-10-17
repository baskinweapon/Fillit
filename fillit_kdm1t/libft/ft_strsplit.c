/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:24:30 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/19 21:01:20 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_delimiter(char **s, char c)
{
	int counter;

	counter = 0;
	if (!s || !c)
		return (0);
	while (*(*s) == c)
		(*s)++;
	while ((*s)[counter] && (*s)[counter] != c)
		counter++;
	return (counter);
}

static char	*ft_strcpy_delimiter(char *dst, char **src, char c)
{
	int i;

	i = 0;
	while (**src == c)
		(*src)++;
	while (**src && **src != c)
	{
		dst[i] = **src;
		(*src)++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strnew_with_check(char **ptr, size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)ft_memalloc(sizeof(char) * (size + 1));
	if (!str)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		return (NULL);
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		wordscounter;
	char	*str;
	char	**array;

	if (!s)
		return (NULL);
	i = 0;
	wordscounter = ft_wordscounter(s, c);
	str = (char*)s;
	array = (char**)ft_memalloc(sizeof(char*) * (wordscounter + 1));
	if (!array)
		return (NULL);
	while (i < wordscounter)
	{
		array[i] = ft_strnew_with_check(array, ft_strlen_delimiter(&str, c));
		array[i] = ft_strcpy_delimiter(array[i], &str, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
