/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:59:48 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:31:22 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (s1 == &s2[i])
			if (s1 >= &s2[i])
			{
				i = len - 1;
				while (i)
				{
					s1[i] = s2[i];
					i -= 1;
				}
				s1[0] = s2[0];
				return (dst);
			}
		i += 1;
	}
	return (ft_memcpy(s1, s2, len));
}
