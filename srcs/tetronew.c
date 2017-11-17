/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetronew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:16:28 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 20:12:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static inline void		setpos(t_pos **tab, int cpt, t_pos curr, t_pos origin)
{
	tab[cpt]->x = curr.x - origin.x;
	tab[cpt]->y = curr.y - origin.y;
}

static void				init_postab(t_pos **tab, char **str)
{
	int		i;
	int		j;
	int		cpt;
	t_pos	origin;
	t_pos	curr;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			curr.x = i;
			curr.y = j;
			origin.x = (!cpt) ? i : origin.x;
			origin.y = (!cpt) ? j : origin.y;
			if (str[i][j] == '#')
				setpos(tab, cpt++, curr, origin);
			j++;
		}
		i++;
		free(str[i]);
	}
	free(str);
}

t_tetro					*tetronew(char **str, char letter)
{
	int		i;
	t_tetro	*res;

	res = (t_tetro *)malloc(sizeof(t_tetro));
	if (!res)
		return (NULL);
	res->letter = letter;
	i = 0;
	while (i < 4)
	{
		res->postab[i] = (t_pos *)malloc(sizeof(t_pos));
		if (!res->postab[i])
		{
			tetrodel(&res);
			return (NULL);
		}
		i++;
	}
	res->postab[4] = NULL;
	init_postab(res->postab, str);
	res->next = NULL;
	return (res);
}
