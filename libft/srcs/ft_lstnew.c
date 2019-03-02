/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:23:37 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/04 09:09:24 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*t;

	if ((t = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		t->content = malloc(content_size);
		if (t->content == NULL)
		{
			free(t);
			return (NULL);
		}
		ft_memcpy(t->content, content, content_size);
		t->content_size = content_size;
		t->next = NULL;
	}
	return (t);
}
