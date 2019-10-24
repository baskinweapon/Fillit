/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:19:28 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/24 11:20:12 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void       tetrimino(const int fd, char **av)
{
    int     reader;
    int     i;
    int     j;
    int     n;
    char    buff[BUFF_SIZE + 1];
    char    tetr[26];
    
    if (fd < 0 || !av)
        write(1, "error", 5);
    while ((reader = read(fd, buff, BUFF_SIZE)) > 0)
    {
       buff[reader] = '\0';
       i = 0;
        while (i < 26)
        {
            tetr[i] = buff[i];
            i++;   
        }
        printf("%s", tetr);
        if (validate(tetr, fd) == 1)
            printf("Yes");
        else 
            printf("No");
    }
    if (reader == -1)
		printf("error");
}

int     main(int ar, char **av)
{
    int fd;
    int i;

    i = 0;
    fd = 0;
    fd = open("test2.txt", O_RDONLY);
    while(av[i])
    {
        tetrimino(fd, &av[i]);
        i++;
    }
    return (0);
}