/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:46:25 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:16:51 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && len > 0)
	{
		dst[i] = src[i];
		i += 1;
		len -= 1;
	}
	while (len > 0)
	{
		dst[i] = '\0';
		i += 1;
		len -= 1;
	}
	return (dst);
}
