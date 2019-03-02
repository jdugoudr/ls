/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:07:40 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/16 10:20:26 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
