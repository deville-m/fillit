/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:55:09 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 20:27:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAP_SIZE 50

#include "libft.h"

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tetro
{
	t_pos			*postab[5];
	char			letter;
	struct s_tetro	*next;
}					t_tetro;

int				num_piece(const char *s);
t_tetro			*input(int fd);
t_tetro			*tetronew(char **str, char letter);
void			tetrodel(t_tetro **alst);
void			tetroadd(t_tetro **alst, t_tetro *new);
void			print_link(t_tetro *elem);
void			print_list(t_tetro *elem);
void			print_map(const char **map);
#endif
