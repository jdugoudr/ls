/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:51:07 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/15 15:35:00 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_cpyfrombg(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i += 1;
	}
	return (dst);
}

static void	*ft_cpyfromend(void *dst, const void *src, size_t len)
{
	while (len != 0)
	{
		*((unsigned char *)dst + len - 1) = *((unsigned char *)src + len - 1);
		len -= 1;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0)
		return (dst);
	else if (src < dst)
		return (ft_cpyfromend(dst, src, len));
	else if (src > dst)
		return (ft_cpyfrombg(dst, src, len));
	else
		return (dst);
}
