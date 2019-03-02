/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittolst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:27:50 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/18 16:23:55 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_splittolst(char *s, char c)
{
	char	**ts;
	t_list	*l;
	int		i;

	i = 0;
	ts = ft_strsplit(s, c);
	if (ts == NULL)
		return (NULL);
	l = ft_strtolst(ts);
	while (*(ts + i) != NULL)
	{
		free(*(ts + i));
		*(ts + i) = NULL;
		i++;
	}
	free(ts);
	ts = NULL;
	return (l);
}
