/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:52:37 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:38:50 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	unsigned int	index_src;

	if (n < 1)
		return (s1);
	index = 0;
	while (s1[index])
		index += 1;
	index_src = 0;
	while (s2[index_src] && n > 0)
	{
		s1[index] = s2[index_src];
		index_src += 1;
		index += 1;
		n -= 1;
	}
	s1[index] = '\0';
	return (s1);
}
