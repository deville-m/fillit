/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:57:40 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 16:08:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

static int	optimal(int nb)
{
	int i;

	nb = nb * 4;
	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

int			solver(t_tetro *lst, char **map, int max)
{
	int		i;
	int		j;
	t_pos	curr;

	if (!lst)
		return (1);
	i = 0;
	while (map[i] && i < max)
	{
		j = 0;
		while (map[i][j] && j < max)
		{
			curr.x = i;
			curr.y = j;
			if (map[i][j++] == '.' && canplace(lst->postab, curr, map, max))
			{
				if (place(lst, curr, map, max))
					return (1);
				else
					unplace(lst, curr, map);
			}
		}
		i++;
	}
	return (0);
}

char		**solver_init(t_tetro *lst)
{
	int		i;
	char	**map;
	int		res;

	tetrorev(&lst);
	tetroletter(lst);
	i = optimal(tetronb(lst));
	res = 0;
	while (!res)
	{
		map = init_map(i);
		res = solver(lst, map, i++);
	}
	return (map);
}
