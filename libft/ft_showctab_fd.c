/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showctab_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:25:37 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:10:09 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_showctab_fd(char **tab, int fd)
{
	size_t	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		ft_putstr_fd("\n", fd);
		i += 1;
	}
}
