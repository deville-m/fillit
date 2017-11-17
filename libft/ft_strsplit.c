/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:03:19 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/12 21:05:32 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		w_size(char const *s, char c, int type)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
			size = size + 1;
		while (s[i] != c && s[i])
			i = i + 1;
		if (type == 2)
			return (i);
		while (s[i] == c && s[i])
			i = i + 1;
	}
	if (type == 1)
		return (size);
	return (0);
}

static char		**make_empty_tab(void)
{
	char	**empty;

	empty = (char **)malloc(sizeof(char *));
	if (!empty)
		return (NULL);
	empty[0] = NULL;
	return (empty);
}

static char		**clear_tab(char **tab, size_t length)
{
	size_t	i;

	if (!tab || !*tab)
		return (NULL);
	i = 1;
	while (i < length)
	{
		ft_memdel((void **)&tab[i]);
		i = i + 1;
	}
	tab[0] = NULL;
	return (tab);
}

static char		**fill_the_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	gen;

	gen = -1;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i = i + 1;
		if (s[i] != c && s[i])
		{
			gen = gen + 1;
			if (!(tab[gen] = ft_strnew(w_size(&s[i], c, 2))))
				return (clear_tab(tab, gen));
		}
		j = 0;
		while (s[i] != c && s[i])
		{
			tab[gen][j] = s[i++];
			j = j + 1;
		}
	}
	tab[gen + 1] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s || w_size(s, c, 1) == 0)
		return (make_empty_tab());
	if (!(tab = (char **)malloc(sizeof(char *) * (w_size(s, c, 1) + 1))))
		return (NULL);
	return (fill_the_tab(tab, s, c));
}
