/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:17:59 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:02:53 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	new_nb;
	unsigned int	divisor;
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		new_nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		new_nb = n;
	divisor = 1;
	while (divisor <= new_nb / 10)
		divisor *= 10;
	while (divisor >= 1)
	{
		ft_putchar_fd(new_nb / divisor + 48, fd);
		new_nb = new_nb % divisor;
		divisor /= 10;
	}
}
