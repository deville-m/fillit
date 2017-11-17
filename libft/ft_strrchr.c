/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:51:04 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:43:09 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	d;

	d = (char)c;
	i = ft_strlen(s);
	if (!c)
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i -= 1;
	}
	if (s[0] == d)
		return ((char *)&s[0]);
	return (NULL);
}
