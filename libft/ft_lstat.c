/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:56:49 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/13 20:07:38 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstat(t_list *alst, size_t nb)
{
	while (alst)
	{
		if (nb == 0)
			return (alst);
		alst = alst->next;
		nb -= 1;
	}
	return (NULL);
}
