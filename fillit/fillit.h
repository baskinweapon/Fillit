/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:50:55 by rmaxima           #+#    #+#             */
/*   Updated: 2019/11/07 15:21:31 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNTITLED_FILLIT_H
#define UNTITLED_FILLIT_H

# define BUFF_SIZE 210
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct		s_flist {
    int            coordinate[8];
    char            c;
    int             x_start;
    int             y_start;
    struct s_flist	*next;
}					t_flist;

typedef struct      s_map {
    char    **map;
}                   t_map;

//map
t_map   *new_map(int size);
int     map_size(int reader);
int     count_list(t_flist *list);

//filling map
void    filling_map(t_flist *list_tetramino);
int     paste(t_map *map, t_flist *list_tetramino, int map_size);
int     ft_y(t_flist *list_tetramino, int map_size);
int     ft_x(t_flist *list_tetramino, int map_size);
void    place(t_flist *list_tetramino, t_map *map, char c);
int     over_size(t_flist *list_tetramino, t_map *map);

//main
t_flist    *read_tetramino(char *file);
int        main(int ar, char **av);

t_flist    *add_list(char *str, int reader);
int		validate(char *str, int reader);

//list tetramino
t_flist     *zero_coordinate(t_flist *ptr);
t_flist     *make_list(char *str, int c);
t_flist    *add_list(char *str, int reader);

#endif //UNTITLED_FILLIT_H

