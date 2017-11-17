/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:31:36 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 16:08:53 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

void				free_map(char **src)
{
	size_t i;

	i = 0;
	while (i < MAP_SIZE)
		free(src[i++]);
	free(src);
}

static inline char	*copy_line(char *src)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (MAP_SIZE))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}
char				**copy_map(char **src)
{
	char	**res;
	size_t	i;

	if (!src)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * MAP_SIZE);
	i = 0;
	while (src[i])
	{
		res[i] = copy_line(src[i]);
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
