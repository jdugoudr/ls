/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:11:52 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/17 16:55:42 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **list, t_list **el, void (*f)(void*))
{
	t_list	*l;

	l = *list;
	if (l == *el)
		*list = (*list)->next;
	else
	{
		while (l->next != *el)
			l = l->next;
		l->next = (*el)->next;
	}
	(*f)((*el)->content);
	free(*el);
	*el = NULL;
}
