/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:27:45 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 19:49:50 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	mem = (char *)malloc(sizeof(char) * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mem[i] = 0;
		i += 1;
	}
	return (mem);
}
