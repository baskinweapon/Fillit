/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:16 by mwilbur           #+#    #+#             */
/*   Updated: 2019/10/25 13:22:15 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		retun (0);
	int ret;
	int fd;
	char buff[BUFF_SIZE + 1];
	t_flist *list;

	ret = 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((checks(buff, fd, ret)) == 0)
		{
			ft_flistclear(list);
			return (0);
		}

	}
}
