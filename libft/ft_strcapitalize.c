/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:55:23 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 14:08:46 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (ft_isalnum(s[i]))
		{
			if (ft_islower(s[i]))
				s[i] -= 32;
			i += 1;
		}
		while (ft_isalnum(s[i]) && s[i])
		{
			if (ft_isupper(s[i]))
				s[i] += 32;
			i += 1;
		}
		if (s[i])
			i += 1;
	}
	return (s);
}
