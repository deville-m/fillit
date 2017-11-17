/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:33:23 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:13:14 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n < 1)
		return (0);
	i = 0;
	while (a[i] && b[i] && i < n - 1)
	{
		if (ft_tolower(a[i]) != ft_tolower(b[i]))
			return (ft_tolower(a[i]) - ft_tolower(b[i]));
		i += 1;
	}
	return (a[i] - b[i]);
}
