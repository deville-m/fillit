/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:30:25 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:13:59 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	i;

	if (ft_strlen(s1) < n)
		copy = ft_strnew(ft_strlen(s1));
	else
		copy = ft_strnew(n);
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i += 1;
	}
	return (copy);
}
