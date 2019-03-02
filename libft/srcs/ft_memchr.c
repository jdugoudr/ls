/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:17:55 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 19:56:02 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *((unsigned char *)s + i) != (unsigned char)c)
		i += 1;
	if (i < n)
		return ((void *)(s + i));
	else
		return (NULL);
}
