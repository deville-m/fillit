/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:54:58 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:58:13 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	char_is_space(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int	trimmed_size(char const *s)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (char_is_space(s[i]) && s[i])
		i += 1;
	while (s[i])
	{
		size += 1;
		i += 1;
	}
	if (size == 0)
		return (size);
	i -= 1;
	while (char_is_space(s[i]) && s[i])
	{
		size -= 1;
		i -= 1;
	}
	return (size);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*trimmed;

	if (!s)
		return (NULL);
	size = trimmed_size(s);
	trimmed = ft_strnew(size);
	if (size == 0)
		return (trimmed);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (char_is_space(s[i]) && s[i])
		i += 1;
	size += i;
	j = 0;
	while (i < size)
	{
		trimmed[j] = s[i];
		j += 1;
		i += 1;
	}
	return (trimmed);
}
