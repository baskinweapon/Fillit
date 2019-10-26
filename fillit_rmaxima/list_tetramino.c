/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetramino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:47:01 by rmaxima           #+#    #+#             */
/*   Updated: 2019/10/26 17:27:33 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void      list_tetramino(char *str)
{
    char **res;
    int i;
    int j;

    if (!(res = (char**)malloc(sizeof(char*) * 4)))
        printf("Error");
    i = 0;
    while (i < 5)
    {
        res[i] = (char*)malloc(sizeof(char) * 4);
        j = 0;
        while (res[i][j])
        {
            res[i][j] = str[i * 4 + j];
            j++;
        }
        i++;
    }
    i = 0;
    while (res[i])
    {
        j = 0;
        while (res[i][j])
        {
            printf("%c", res[i][j]);
            j++;
        }
        i++;
    }
}

// int     main()
// {
//     char str[20] = "....\n..##\n..##\n....\n";
//     list_tetramino(str);
// }