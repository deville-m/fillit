/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:57:00 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:12:37 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) ||
			(ft_tolower(haystack[i + j]) == ft_tolower(needle[j])))
		{
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}
