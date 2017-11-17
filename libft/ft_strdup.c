/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:16:27 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:34:22 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	if (!(copy = ft_strnew(ft_strlen(s1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i += 1;
	}
	return (copy);
}
