/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:38:59 by alex              #+#    #+#             */
/*   Updated: 2019/10/28 15:31:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int     tetramino(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == '#')
        {
            if ((i + 1) < 20 && str[i + 1] == '#')
                count++;
            if ((i - 5) >= 0 && str[i - 5] == '#')
                count++;
            if ((i + 5) < 20 && str[i + 5] == '#')
                count++;
            if ((i - 1) >= 0 && str[i - 1] == '#')
                count++;     
        }
        i++;
    }
    if (count == 6 || count == 8)
        return (1);
    return (0);
}

int     validate(char *str)
{
    int i;
    int count;
    int ncounter;
    int tcounter;

    i = 0;
    count = 0;
    ncounter = 0;
    tcounter = 0;
    while (str[i])
    {
        while (str[i] != '\n' && str[i])
        {
            count++;
            if (str[i] == '#')
            {
              tcounter++;  
            }
            i++;        
        }
        ncounter++;
        if (count != 4)
            return (0);
        count = 0;
        i++;
    }
    if (tcounter != 4)
        return (0);
    if (ncounter != 4)
        return (0);
    if (tetramino(str) == 0)
        return (0);
    return (1);
}

// int main()
// {
//     char *str = "Hello\nmy\nname\nis\n";
//     char *str2 = "..##\n..##\n....\n....\n";
//     int fd = 1;
//     printf("str = %d\n", validate(str, fd));
//     printf("str2 = %d\n", validate(str2, fd));
//     fd = -1;
//     printf("fd<0 = %d\n", validate(str, fd));
//     return (0);
// }