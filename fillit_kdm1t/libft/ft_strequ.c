/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:12:39 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/19 19:30:05 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*first;
	unsigned char	*second;

	if (!s1 || !s2)
		return (0);
	i = 0;
	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (0);
		i++;
	}
	if ((!first[i] && second[i]) || (first[i] && !second[i]))
		return (0);
	return (1);
}
