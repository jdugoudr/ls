/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:08:05 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 19:41:49 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *((unsigned char *)src + i) != (unsigned char)c)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i += 1;
	}
	if (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		return (dst + i + 1);
	}
	else
		return (NULL);
}
