//
// Created by user on 06.11.2019.
//

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

t_map   *new_map(int size);
int     map_size(int reader);
int     count_list(t_flist *list);

t_map   *filling_map(t_flist *list_tetramino);

t_flist    *add_list(char *str, int reader);
int		validate(char *str, int reader);

#endif //UNTITLED_FILLIT_H
