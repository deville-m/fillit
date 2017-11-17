/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:42:32 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:38:11 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	index;
	unsigned int	index_src;

	index = 0;
	while (s1[index])
		index += 1;
	index_src = 0;
	while (s2[index_src])
	{
		s1[index + index_src] = s2[index_src];
		index_src += 1;
	}
	s1[index + index_src] = '\0';
	return (s1);
}
