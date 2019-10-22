/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:38:59 by alex              #+#    #+#             */
/*   Updated: 2019/10/22 12:23:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     valid_tetramin(char *str)
{
    int i;
    int brink;
    int d[5][5];
    int j;
    int k;
    int t;
    
    brink = 0;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (d[j])
        {
            k = 0;
            while (d[j][k])
            {
                if (str[i] == '#')
                    d[j][k] = 1;
                if (str[i] == '.')
                    d[j][k] = 0;
                if (str[i] == '\n')
                    j++;;
                k++;
            }
        }
    }
   for (t=0; t<j; ++t)
    {
        for (i=0; i<k; ++i)
            printf("%d  ", d[t][i]);
    printf ("\n");
    }
    return (1);
}

int     validate(char *str, int fd)
{
    int i;
    int count;
    int ncounter;
    int icounter;

    
    if (fd < 0)
        return (0);
    i = 0;
    count = 0;
    ncounter = 0;
    icounter = 0;
    while (str[i])
    {
        while (str[i] != '\n' && str[i])
        {
            count++;
            if (str[i] == '#')
            {
              icounter++;  
            }
            i++;        
        }
        ncounter++;
        if (count != 4)
            return (0);
        count = 0;
        i++;
    }
    if (icounter != 4)
        return (0);
    if (ncounter != 4)
        return (0);
    if (valid_tetramin(str) == 0)
        return (0);
    return (1);
}

int main()
{
    char *str = "Hello\nmy\nname\nis\n";
    char *str2 = "..##\n....\n..#.\n...#\n";
    int fd = 1;
    printf("str = %d\n", validate(str, fd));
    printf("str2 = %d\n", validate(str2, fd));
    fd = -1;
    printf("fd<0 = %d\n", validate(str, fd));
    return (0);
}