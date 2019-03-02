/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:15:39 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/18 18:07:56 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strtolst(char *s[])
{
	t_list	*l;
	t_list	*newel;
	size_t	i;

	i = 1;
	if (s == NULL)
		return (NULL);
	newel = ft_lstnew(s[0], ft_strlen(s[0]) + 1);
	l = newel;
	if (newel == NULL)
		return (NULL);
	while (s[i])
	{
		newel->next = ft_lstnew(s[i], ft_strlen(s[i]) + 1);
		if (newel->next == NULL)
		{
			ft_lstdelstr(&l);
			return (NULL);
		}
		newel = newel->next;
		i += 1;
	}
	return (l);
}
