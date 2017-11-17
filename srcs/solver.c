/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:57:40 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 23:56:29 by mdeville         ###   ########.fr       */
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

static char	**solver(t_tetro *lst, char **map, int max)
{
	t_tetro	*curr;
	char	**newmap;

	if (!lst)
		return(map);
	curr = lst;
	while (curr)
	{
		newmap = copy_map(map);
		if (setmap(curr, newmap, max))
		{
			newmap = solver(lst->next, newmap, max);
			if (newmap)
				return (newmap);
		}
		free_map(newmap);
		curr = curr->next;
	}
	return (NULL);
}

char		**solver_init(t_tetro *lst)
{
	char	**map;
	char	**res;
	int		i;

	map = (char **)malloc(sizeof(char *) * (MAP_SIZE + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < MAP_SIZE)
	{
		map[i] = (char *)malloc(sizeof(char) * (MAP_SIZE + 1));
		if (!map)
		{
			free_map(map);
			return (NULL);
		}
		ft_memset(map[i], '.', MAP_SIZE - 1);
		map[i++][MAP_SIZE] = '\0';
	}
	/*map[i] = NULL;
	i = optimal(tetronb(lst));
	while (!(res = solver(lst, map, i)))
		i++;*/
	res = solver(lst, map, 4);
	free_map(map);
	print_map(res);
	return (res);
}
