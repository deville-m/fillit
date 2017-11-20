/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:54:21 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 11:00:41 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	while (tmp[i])
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

void	print_map(char **map)
{
	size_t i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}
