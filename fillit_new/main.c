/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:51:13 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/07 16:01:56 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist    *read_tetramino(char *file)
{
    int reader;
    char buff[545];
    int fd;

    reader = 0;
    fd = open(file, O_RDONLY);
    reader = read(fd, buff, 545);
    close(fd);
    if (reader > 544 || reader < 19)
        return (NULL);
    buff[reader] = '\0';
    if (validate(buff, reader) == 0)
        return (NULL);
    else
        return (add_list(buff, reader));
}

int        main(int ar, char **av)
{
    t_flist *list_tetramino;

    if (ar != 2)
    {
        ft_putstr("usage: ./fillit source_file\n");
        return (1);
    }
    if ((list_tetramino = read_tetramino(av[1])) == NULL)
    {
        ft_putstr("error\n");
        return (1);
    }
    filling_map(list_tetramino);
    return (0);
}
