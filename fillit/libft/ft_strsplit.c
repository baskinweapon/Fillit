/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:11:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/09/18 15:58:25 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_count_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	*is_word(char *s, char c)
{
	char	*str;

	str = s;
	while (*s && *s != c)
		s++;
	*s = '\0';
	return (ft_strdup(str));
}

static void	is_free(char **s, size_t i)
{
	while (i--)
		ft_strdel(&(s[i]));
	free(*s);
}

static char	**is_words(char *s, char c, size_t count)
{
	char	**strs;
	char	*str;
	size_t	i;

	i = 0;
	if ((strs = (char**)ft_memalloc(sizeof(char*) * (count + 1))))
	{
		while (i < count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(str = is_word(s, c)))
				{
					is_free(strs, i);
					return (NULL);
				}
				strs[i++] = str;
				s += (ft_strlen(str) + 1);
			}
		}
		strs[i] = NULL;
	}
	return (strs);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strs;
	char	*str;

	if (!s || !(str = ft_strdup((char*)s)))
		return (NULL);
	strs = is_words(str, c, is_count_words(str, c));
	free(str);
	return (strs);
}
