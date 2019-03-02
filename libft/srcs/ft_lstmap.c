/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:22:38 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/15 16:41:25 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstwdel(t_list **list)
{
	t_list	*p;

	p = (*list)->next;
	while (p != NULL)
	{
		free((*list)->content);
		free((*list));
		*list = p;
		p = (*list)->next;
	}
	*list = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*newel;
	t_list	*cpy;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = NULL;
	cpy = (*f)(lst);
	if ((newel = ft_lstnew(cpy->content, cpy->content_size)) == NULL)
		return (NULL);
	newlist = newel;
	lst = lst->next;
	while (lst != NULL)
	{
		cpy = (*f)(lst);
		newel->next = ft_lstnew(cpy->content, cpy->content_size);
		if (newel->next == NULL)
		{
			ft_lstwdel(&newlist);
			return (NULL);
		}
		lst = lst->next;
		newel = newel->next;
	}
	return (newlist);
}
