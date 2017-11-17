/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:31:20 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:52:49 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new_one;

	if (!s || !f)
		return (NULL);
	new_one = ft_strnew(ft_strlen(s));
	if (!new_one)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_one[i] = f(s[i]);
		i += 1;
	}
	return (new_one);
}
