/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:41:52 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/17 16:56:11 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(int n, int nbd, int len_base)
{
	if ((n / len_base) != 0)
		return (ft_nbdigit(n / len_base, nbd + 1, len_base));
	else
		return (nbd + 1);
}

static int	ft_looknegatif(int *nbd, unsigned int *nb, int n)
{
	int	p;

	p = 1;
	if (n < 0)
	{
		p *= -1;
		*nbd += 1;
		*nb = -n;
	}
	else
		*nb = n;
	return (p);
}

char		*ft_stoa_base(short n, const char *base)
{
	int				len_base;
	int				nbd;
	char			*r;
	int				p;
	unsigned int	nb;

	nb = 0;
	len_base = ft_strlen(base);
	nbd = ft_nbdigit(n, 0, len_base);
	p = ft_looknegatif(&nbd, &nb, n);
	r = (char *)malloc((nbd + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[nbd] = '\0';
	if (p < 0)
		*r = '-';
	while ((nb / len_base) > 0)
	{
		*(r + nbd - 1) = *(base + (nb % len_base));
		nb = nb / len_base;
		nbd -= 1;
	}
	*(r + nbd - 1) = *(base + (nb % len_base));
	return (r);
}
