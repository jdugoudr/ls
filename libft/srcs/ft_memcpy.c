/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:01:05 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/24 15:00:34 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n != 0)
	{
		n -= 1;
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	}
	return (dst);
}
