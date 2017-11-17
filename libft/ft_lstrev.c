/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:21:54 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/11 20:44:00 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*temp;
	t_list	*first;

	if (!alst || !*alst || !(*alst)->next)
		return ;
	first = *alst;
	*alst = (*alst)->next;
	first->next = NULL;
	while (*alst)
	{
		temp = first;
		first = *alst;
		*alst = (*alst)->next;
		first->next = temp;
	}
	*alst = first;
}
