/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:21:33 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/18 11:36:25 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char *s, const t_list *e)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (e != NULL)
	{
		while (j < e->content_size - 1)
		{
			s[i] = ((char *)(e->content))[j];
			i++;
			j++;
		}
		j = 0;
		e = e->next;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_lstjoinstr(const t_list *l)
{
	char			*s;
	const t_list	*e;
	size_t			size;

	size = 0;
	e = l;
	while (e != NULL)
	{
		size += e->content_size - 1;
		e = e->next;
	}
	s = (char *)malloc((size + 1) * sizeof(char));
	e = l;
	return (fill_str(s, e));
}
