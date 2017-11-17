/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:13:18 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:54:55 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*part;

	if (!s || start > ft_strlen(s) || len + start > ft_strlen(s) + 1)
		return (NULL);
	size = 1;
	i = start;
	while (s[i++] && size < len)
		size += 1;
	if (!(part = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		part[i] = s[start];
		i += 1;
		start += 1;
		len -= 1;
	}
	return (part);
}
