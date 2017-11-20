/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:59:59 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 11:00:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

void	tetroletter(t_tetro *alst)
{
	t_tetro *curr;
	char	letter;

	letter = 'A';
	if (!alst)
		return ;
	curr = alst;
	while (curr)
	{
		curr->letter = letter++;
		curr = curr->next;
	}
}

void	tetrorev(t_tetro **alst)
{
	t_tetro *prev;
	t_tetro *curr;
	t_tetro *tmp;

	if (!alst || !*alst)
		return ;
	curr = *alst;
	prev = NULL;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*alst = prev;
}

int		tetronb(t_tetro *alst)
{
	int i;

	if (!alst)
		return (0);
	i = 0;
	while (alst)
	{
		i++;
		alst = alst->next;
	}
	return (i);
}

void	tetrodel(t_tetro **alst)
{
	int		i;
	t_tetro	*tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		i = 0;
		while ((*alst)->postab[i])
			free((*alst)->postab[i++]);
		free(*alst);
		*alst = tmp;
	}
}

void	tetroadd(t_tetro **alst, t_tetro *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
