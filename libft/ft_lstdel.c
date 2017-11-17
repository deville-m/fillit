/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:04:13 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/10 16:37:40 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*stock;

	if (!alst || !*alst || !del)
		return ;
	while ((*alst))
	{
		stock = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = stock;
	}
}
