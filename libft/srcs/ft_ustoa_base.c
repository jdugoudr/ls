/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:56:19 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:16:26 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(unsigned short n, int nbd, int len_base)
{
	if ((n / len_base) != 0)
		return (ft_nbdigit(n / len_base, nbd + 1, len_base));
	else
		return (nbd + 1);
}

char		*ft_ustoa_base(unsigned short n, const char *base)
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
