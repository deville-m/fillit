/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:31:36 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 15:20:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

void				free_map(char **src)
{
	size_t i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
		free(src[i++]);
	free(src);
}

char				**init_map(int size)
{
	int		i;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!map)
		{
			free_map(map);
			return (NULL);
		}
		ft_memset(map[i], '.', size);
		map[i++][size] = '\0';
	}
	map[i] = NULL;
	return (map);
}

static inline char	*copy_line(char *src, int max)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (max + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i] && i < max)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char				**copy_map(char **src, int max)
{
	char	**res;
	int		i;

	if (!src)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (max + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i] && i < max)
	{
		res[i] = copy_line(src[i], max);
		if (!res[i])
		{
			free_map(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
