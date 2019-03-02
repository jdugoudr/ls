/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:08:48 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/04 19:52:53 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creat at first for ft_divstr.
** like lstnew but without malloc the content.
** usefull when the content already malloc.
** content_size become useless.
*/

t_list	*ft_lstnewstr(char *content)
{
	t_list	*t;

	if ((t = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		t->content = content;
		t->content_size = 0;
		t->next = NULL;
	}
	return (t);
}
