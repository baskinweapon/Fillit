/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:16 by mwilbur           #+#    #+#             */
/*   Updated: 2019/11/03 12:12:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int ret;
	int fd;
	int i;
    char tetr[21];
	char buff[BUFF_SIZE + 1];
	// t_flist *list = NULL;

	ret = 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		i = 0;
        while (i < 20)
        {
            tetr[i] = buff[i];
            i++;
        }
        tetr[i] = '\0';
		if ((validate(tetr, fd)) == 0)
			printf("validerror");
		array_tetramino(tetr);
	}
}
