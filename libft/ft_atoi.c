/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:11:10 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:46:48 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	long	result;

	neg = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str += 1;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str += 1;
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		if (((result == 922337203685477580 && (*(str) - 48) > 7)
			|| (result == 922337203685477580 && (*(str) - 48) > 8 && neg == -1))
				|| result > 922337203685477580)
			return ((neg == 1) ? -1 : 0);
		result = (result * 10) + (*(str++) - 48);
	}
	return (result * neg);
}
