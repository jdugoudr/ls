/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:43:06 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/15 11:01:16 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	if (s == NULL || f == NULL)
		return ;
	l = ft_strlen(s);
	while (i < l)
	{
		(*f)(i, s + i);
		i += 1;
	}
}
