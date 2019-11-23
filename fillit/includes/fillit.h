/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:50:29 by mwilbur           #+#    #+#             */
/*   Updated: 2019/11/23 17:55:54 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 210
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef	struct		s_flist
{
	int				coordinate[8];
	char			c;
	int				x_start;
	int				y_start;
	struct s_flist	*next;
}					t_flist;

typedef	struct		s_map
{
	char			**map;
}					t_map;

t_map				*new_map(int size);
int					map_size(int ret);
int					count_list(t_flist *list);
void				filling_map(t_flist *list_tetramino);
int					paste(t_map *map, t_flist *list_tetramino, int map_size);
int					ft_y(t_flist *list_tetramino, int map_size);
int					ft_x(t_flist *list_tetramino, int map_size);
void				place(t_flist *list_tetramino, t_map *map, char c);
int					over_size(t_flist *list_tetramino, t_map *map);
t_flist				*read_tetramino(char *file);
t_flist				*add_list(char *str, int ret);
int					validate(char *str, int ret);
t_flist				*zero_coordinate(t_flist *ptr);
t_flist				*make_list(char *str, int c);
t_flist				*add_list(char *str, int ret);

#endif
