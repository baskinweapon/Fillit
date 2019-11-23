/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:51:13 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/23 17:53:45 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_flist		*read_tetramino(char *file)
{
	int		ret;
	char	buff[545];
	int		fd;

	ret = 0;
	fd = open(file, O_RDONLY);
	ret = read(fd, buff, 545);
	close(fd);
	if (ret > 544 || ret < 19)
		return (NULL);
	buff[ret] = '\0';
	if (validate(buff, ret) == 0)
		return (NULL);
	else
		return (add_list(buff, ret));
}

int			main(int argc, char **argv)
{
	t_flist	*list_tetramino;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((list_tetramino = read_tetramino(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	filling_map(list_tetramino);
	return (0);
}
