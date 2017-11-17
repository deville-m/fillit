/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:09:10 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 23:00:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			canplace(t_pos **tab, t_pos pos, char **map, int max)
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

static void		place(t_pos **tab, t_pos pos, char letter, char **map)
{
	int i;

	i = 0;
	while (tab[i])
	{
		map[tab[i]->x + pos.x][tab[i]->y + pos.y] = letter;
		i++;
	}
}

int			setmap(t_tetro *elem, char **map, int max)
{
	int i;
	int j;
	t_pos curr;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			curr.x = i;
			curr.y = j;
			if (canplace(elem->postab, curr, map, max))
			{
				place(elem->postab, curr, elem->letter, map);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
