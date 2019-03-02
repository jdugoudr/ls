/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:59:34 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/23 12:41:28 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *l, t_list *mnew)
{
	if (l == NULL || mnew == NULL)
		return ;
	while (l->next != NULL)
		l = l->next;
	l->next = mnew;
}
