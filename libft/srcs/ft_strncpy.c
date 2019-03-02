/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:11:38 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/08 17:20:35 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0' && i < len)
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	while (i < len)
	{
		*(dst + i) = '\0';
		i += 1;
	}
	return (dst);
}
