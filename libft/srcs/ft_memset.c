/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:29:15 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/11 14:23:10 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len != 0)
	{
		len -= 1;
		*((unsigned char *)b + len) = (unsigned char)c;
	}
	return (b);
}
