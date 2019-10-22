/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:19:28 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/21 16:37:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void       tetrimino(const int fd, char **av)
{
    int     reader;
    int     i;
    char    buff[BUFF_SIZE + 1];
    char    tetramin[4];
    s_fillit *tetro;
    s_fillit *head;
    

    if (fd < 0 || !av)
        write(1, "error", 5);
    while ((reader = read(fd, buff, BUFF_SIZE)) > 0)
    {
       
    }
    
}

int     main(int ar, char **av)
{
    int fd;
    int i;

    i = 0;
    fd = 0;
    fd = open("test.txt", O_RDONLY);
    while(av[i])
    {
        tetrimino(fd, &av[i]);
    }
}