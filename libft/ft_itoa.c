/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:11:14 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:59:18 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	create_unsigned(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int			int_length(unsigned int n)
{
	unsigned int	i;
	unsigned int	divisor;

	i = 1;
	divisor = 1;
	while (divisor <= n / 10)
	{
		divisor *= 10;
		i += 1;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	unsigned int	new_nb;
	unsigned int	divisor;
	unsigned int	i;
	char			*str;

	new_nb = create_unsigned(n);
	divisor = 1;
	while (divisor <= new_nb / 10)
		divisor *= 10;
	i = int_length(new_nb);
	n < 0 ? i++ : i;
	if (!(str = ft_strnew(i)))
		return (NULL);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (divisor >= 1)
	{
		str[i++] = (new_nb / divisor) + '0';
		new_nb %= divisor;
		divisor /= 10;
	}
	return (str);
}
