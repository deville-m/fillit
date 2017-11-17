/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:30:59 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:42:27 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	d;

	d = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i += 1;
	}
	if (!c)
		return ((char *)&s[i]);
	return (NULL);
}
