/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:24:21 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 20:00:02 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	while (i < n && r == 0)
	{
		r = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		i += 1;
	}
	return (r);
}
