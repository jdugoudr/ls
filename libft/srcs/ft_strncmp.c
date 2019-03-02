/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:36:24 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/15 10:49:15 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != '\0' && n > 0)
	{
		n -= 1;
		return (ft_strncmp(s1 + 1, s2 + 1, n));
	}
	else if (n != 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (0);
}
