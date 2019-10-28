/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:38:59 by alex              #+#    #+#             */
/*   Updated: 2019/10/25 11:58:43 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int     check_tetramino(char *str)
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

int     check_input(char *str)
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

int     checks(char *str, int fd, int ret)
{
    if (ret == -1 || fd < 0)
        return (0);
    if (check_input(str) == 0)
        return (0);
    if (check_tetramino(str) == 0)
        return (0);
}
