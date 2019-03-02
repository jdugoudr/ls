/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:09:29 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/04 12:42:24 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelstr(t_list **list)
{
	t_list	*pnext;
	t_list	*pdel;

	pdel = *list;
	while (pdel != NULL)
	{
		pnext = pdel->next;
		if (pdel->content != NULL)
		{
			free(pdel->content);
			pdel->content = NULL;
		}
		free(pdel);
		pdel = pnext;
	}
	*list = NULL;
}
