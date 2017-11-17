/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:49:05 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/11 17:54:03 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_lst(t_list *to_free)
{
	t_list	*temp;

	while (to_free)
	{
		temp = to_free;
		to_free = to_free->next;
		if (temp->content)
			free(temp->content);
		if (temp)
			free(temp);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*stock;

	if (!lst || !f)
		return (NULL);
	new_list = f(lst);
	if (new_list == NULL)
		return (NULL);
	stock = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = f(lst);
		if (!new_list->next)
		{
			free_lst(stock);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (stock);
}
