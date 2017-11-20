/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:09:10 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 12:55:40 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		canplace(t_pos **tab, t_pos pos, char **map, int max)
{
	int i;
	int xtmp;
	int ytmp;

	i = 0;
	while (tab[i])
	{
		xtmp = tab[i]->x + pos.x;
		ytmp = tab[i]->y + pos.y;
		if (xtmp >= max || xtmp < 0
			|| ytmp >= max || ytmp < 0
			|| map[xtmp][ytmp] != '.')
			return (0);
		i++;
	}
	return (1);
}

char	**place(t_tetro *elem, t_pos pos, char **map, int max)
{
	int		i;
	t_pos	**tab;
	char	**newmap;

	i = 0;
	newmap = copy_map(map, max);
	tab = elem->postab;
	while (tab[i])
	{
		newmap[tab[i]->x + pos.x][tab[i]->y + pos.y] = elem->letter;
		i++;
	}
	return (solver(elem->next, newmap, max));
}
