/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:19:28 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/18 16:11:03 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void       tetrimino(const int fd, char **av)
{
    int reader;
    int i;
    char    buff[BUFF_SIZE + 1];
    char    tetramin[4];
    

    if (fd < 0 || !av)
        write(1, "error", 5);
    while ((reader = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[reader] = '\0';
        i = 0;
        while(reader > 0)
        {
            
            printf("%c", buff[i]);
            reader--;
            i++;
        }
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