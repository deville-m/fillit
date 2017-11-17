/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:20:28 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/08 09:50:43 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int nb)
{
	unsigned int	new_nb;
	unsigned int	divisor;
	unsigned int	i;

	i = 0;
	if (nb < 0)
	{
		new_nb = -nb;
		ft_putchar('-');
	}
	else
		new_nb = nb;
	divisor = 1;
	while (divisor <= new_nb / 10)
		divisor *= 10;
	while (divisor >= 1)
	{
		ft_putchar(new_nb / divisor + 48);
		new_nb = new_nb % divisor;
		divisor /= 10;
	}
}
