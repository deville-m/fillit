/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:26:51 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/16 16:29:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	s_is_correct(const char *s)
{
	int	i;
	int	hash;

	i = 0;
	hash = 0;
	while (s[i] && i < 18)
	{
		if (s[i] != '.' && s[i] != '#')
			return (0);
		if (s[i] == '#')
			hash += 1;
		i += 1;
	}
	if (i != 16 || hash != 4)
		return (0);
	return (1);
}

int			num_piece(const char *s)
{
	int	result;
	int	i;

	if (!s || !s_is_correct(s))
		return (1);
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (i % 4 != 0 && s[i - 1] == '#')
				result += 8;
			if (3 < i && s[i - 4] == '#')
				result += 4;
			if (i % 4 != 3 && s[i + 1] == '#')
				result += 2;
			if (i < 12 && s[i + 4] == '#')
				result += 1;
			if (result < 4096)
				result <<= 4;
		}
		i += 1;
	}
	return (result);
}
