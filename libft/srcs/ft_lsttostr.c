/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:11:59 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/17 17:38:21 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttostr(const t_list *l, size_t len)
{
	char		**s;
	size_t		i;

	i = 0;
	if (l == NULL)
		return (NULL);
	s = (char **)malloc((len + 1) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		*(s + i) = ((char*)(l->content));
		l = l->next;
		i++;
	}
	return (s);
}
