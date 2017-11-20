/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:55:09 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 12:41:45 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAP_SIZE 50

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

char				**solver_init(t_tetro *alst);
char				**solver(t_tetro *lst, char **map, int max);
char				**init_map(void);
char				**copy_map(char **map, int max);
int					num_piece(const char *s);
int					tetronb(t_tetro *alst);
int					setmap(t_tetro *elem, char **map, int max);
t_tetro				*input(int fd);
t_tetro				*tetronew(char **str);
void				tetroletter(t_tetro *alst);
void				tetrorev(t_tetro **alst);
void				tetrodel(t_tetro **alst);
void				tetroadd(t_tetro **alst, t_tetro *new);
void				print_link(t_tetro *elem);
void				print_list(t_tetro *elem);
void				print_map(char **map);
void				free_map(char **map);
char				**place(t_tetro *elem, t_pos pos, char **map, int max);
int					canplace(t_pos **tab, t_pos pos, char **map, int max);
#endif
