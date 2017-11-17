/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiterif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:54:13 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/12 15:04:46 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiterif(t_list *alst, void (*f)(t_list *elem),
			int (*cmp)(void const *s1, void const *s2), void const *content_ref)
{
	if (!f || !cmp || !content_ref)
		return ;
	while (alst)
	{
		if ((*cmp)(alst->content, content_ref) == 0)
			(f)(alst);
		alst = alst->next;
	}
}
