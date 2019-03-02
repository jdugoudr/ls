/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:53:22 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 19:42:55 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;
	size_t	ldst;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	i = 0;
	while (*(src + i) != '\0' && (ldst + i + 1) < size)
	{
		*(dst + ldst + i) = *(src + i);
		i += 1;
	}
	*(dst + ldst + i) = '\0';
	if (ldst <= size)
	{
		return (ldst + lsrc);
	}
	else
		return (lsrc + size);
}
