/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:12:00 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:45:09 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (len - j <= 0)
				return (NULL);
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j += 1;
		}
		i += 1;
		len -= 1;
	}
	return (NULL);
}
