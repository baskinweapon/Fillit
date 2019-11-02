/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:15:02 by mwilbur           #+#    #+#             */
/*   Updated: 2019/10/28 14:52:03 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_flist {
	char 			tetr[21];
	struct s_flist	*next;
}					t_flist;

int		check_tetramino(char *str);
int		check_input(char *str);
int		checks(char *str, int fd, int ret);
t_flist	*ft_flstnew(char *str, size_t len);
t_flist	*ft_flstclear(t_flist *lst);
void	ft_flstdisplay(t_flist *lst);

#endif
