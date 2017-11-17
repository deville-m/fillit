/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:10:26 by rbaraud           #+#    #+#             */
/*   Updated: 2017/11/12 15:12:24 by rbaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *alst, void const *content_ref,
			int (*cmp)(void const *s1, void const *s2))
{
	while (alst)
	{
		if ((*cmp)(alst->content, content_ref) == 0)
			return (alst);
		alst = alst->next;
	}
	return (alst);
}
