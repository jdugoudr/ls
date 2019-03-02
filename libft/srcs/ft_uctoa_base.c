/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uctoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:55:38 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/17 16:54:37 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(unsigned char n, int nbd, int len_base)
{
	if ((n / len_base) != 0)
		return (ft_nbdigit(n / len_base, nbd + 1, len_base));
	else
		return (nbd + 1);
}

char		*ft_uctoa_base(unsigned char n, const char *base)
{
	int				len_base;
	int				nbd;
	char			*r;

	len_base = ft_strlen(base);
	nbd = ft_nbdigit(n, 0, len_base);
	r = (char *)malloc((nbd + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[nbd] = '\0';
	while ((n / len_base) > 0)
	{
		*(r + nbd - 1) = *(base + (n % len_base));
		n = n / len_base;
		nbd -= 1;
	}
	*(r + nbd - 1) = *(base + (n % len_base));
	return (r);
}
