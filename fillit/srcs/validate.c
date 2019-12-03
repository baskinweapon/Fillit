/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:38:59 by alex              #+#    #+#             */
/*   Updated: 2019/12/03 17:22:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		count_tetra(char *str)
{
    int i;
    int count;
    int ncounter;
    int tcounter;

    i = 0;
    count = 0;
    ncounter = 0;
    tcounter = 0;
    while (i < 19)
    {
        if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
            return (0);
        if (str[i] == '\n' && !(((i + 1) % 5) == 0))
            return (0);
        if (str[i] == '#')
            tcounter++;
        i++;
    }
    if (!str[i] || str[i] != '\n')
        return 0;
    if (tcounter != 4)
        return (0);
    return (1);
}

int		tetramino(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < 19)
    {
        if (str[i] == '#')
        {
            if ((i + 1) < 19 && str[i + 1] == '#')
                count++;
            if ((i - 5) >= 0 && str[i - 5] == '#')
                count++;
            if ((i + 5) < 19 && str[i + 5] == '#')
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

int		validate(char *str, int ret)
{
    int i;

    i = 0;
    while (i <= ret)
    {
        if (count_tetra(str + i) == 0)
            return (0);
        if (tetramino(str + i) == 0)
            return (0);
        i += 21;
    }
    return (1);
}
