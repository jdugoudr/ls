/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:55:51 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/18 16:22:28 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*pnext;
	t_list	*pdel;

	pdel = (*alst);
	while (pdel != NULL)
	{
		pnext = pdel->next;
		(*del)((pdel)->content, (pdel)->content_size);
		free(pdel);
		pdel = pnext;
	}
	(*alst) = NULL;
}
