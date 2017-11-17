/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:57:40 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 16:13:16 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**solver_init(t_list *lst)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * MAP_SIZE);
	if (!map)
		return (NULL);
	i = 0;
	while (i < MAP_SIZE)
		map[i++] = (char *)malloc(sizeof(char) * MAP_SIZE);
	return (solver(lst, map));
}

char		**solver(t_list *lst, char **map)
{
	t_list *curr;

	curr = lst;
	while (curr)
	{
		if (setmap(curr, map, max))
		curr->next;
	}
}
