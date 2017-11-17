/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:16:10 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/11 21:28:47 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **alst1, t_list *alst2)
{
	t_list	*temp;

	if (!alst1 || !alst2)
		return ;
	if (*alst1)
	{
		temp = *alst1;
		while (temp->next)
			temp = temp->next;
		temp->next = alst2;
	}
	else
		*alst1 = alst2;
}
