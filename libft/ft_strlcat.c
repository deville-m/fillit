/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:28:50 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/12 23:01:06 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	while (i < dst_len && i < size)
		i += 1;
	if (i == size)
		return (size + ft_strlen(src));
	j = 0;
	while (size - i > 1 && src[j])
	{
		dst[i] = src[j];
		i += 1;
		j += 1;
	}
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
