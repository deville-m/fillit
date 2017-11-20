/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:57:40 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 13:47:47 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	optimal(int nb)
{
	int i;

	nb = nb * 4;
	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

char		**solver(t_tetro *lst, char **map, int max)
{
	int		i;
	int		j;
	char	**newmap;
	t_pos	curr;

	if (!lst)
		return (map);
	i = 0;
	newmap = NULL;
	while (map[i] && i < max)
	{
		j = 0;
		while (map[i][j] && j < max)
		{
			curr.x = i;
			curr.y = j;
			if (map[i][j] == '.' && canplace(lst->postab, curr, map, max)
				&& (newmap = place(lst, curr, map, max)) != NULL)
				return (newmap);
			j++;
		}
		i++;
	}
	free_map(newmap);
	return (NULL);
}

char		**solver_init(t_tetro *lst)
{
	int		i;
	char	**map;
	char	**res;

	tetrorev(&lst);
	tetroletter(lst);
	map = init_map();
	i = optimal(tetronb(lst));
	while (!(res = solver(lst, map, i)))
		i++;
	free_map(map);
	return (res);
}
