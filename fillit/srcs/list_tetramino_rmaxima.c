/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetramino_rmaxima.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:47:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/02 19:01:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void      array_tetramino(char *str)
{
    char **res;
    int i;
    int j;

    if (!(res = (char**)malloc(sizeof(char*) * 4)))
        printf("Error");
    i = 0;
    while (i < 4)
    {
        res[i] = (char*)malloc(sizeof(char) * 4);
        j = 0;
        while (j < 5)
        {
            res[i][j] = str[i * 5 + j];
            j++;
        }
        printf("%d = %s", i, res[i]);
        i++;
    }
}

