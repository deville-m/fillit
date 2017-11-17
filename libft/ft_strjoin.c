/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:46:42 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:56:29 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = ft_strnew(i)))
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		result[j] = s1[i];
		j += 1;
		i += 1;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		j += 1;
		i += 1;
	}
	return (result);
}
