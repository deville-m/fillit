/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:59:59 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/17 20:30:12 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

void	print_link(t_tetro *elem)
{
	int		i;
	t_pos	**tmp;

	if (!elem)
		return ;
	tmp = elem->postab;
	ft_putstr("Piece ");
	ft_putchar(elem->letter);
	ft_putchar('\n');
	i = 0;
	while(tmp[i])
	{
		ft_putnbr(tmp[i]->x);
		ft_putstr(", ");
		ft_putnbr(tmp[i]->y);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	print_list(t_tetro *elem)
{
	if (!elem)
		return ;
	while (elem)
	{
		print_link(elem);
		elem = elem->next;
	}
}

void	tetrodel(t_tetro **alst)
{
	int i;
	t_tetro *tmp;

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
