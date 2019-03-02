/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:33:00 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/04 19:54:17 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(long n, int nbd)
{
	if ((n / 10) != 0)
		return (ft_nbdigit(n / 10, nbd + 1));
	else
		return (nbd + 1);
}

static int	ft_looknegatif(int *nbd, unsigned long long *nb, long n)
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

char		*ft_ltoa(long n)
{
	unsigned long long	nb;
	int					nbd;
	char				*r;
	int					p;

	p = 1;
	nbd = ft_nbdigit(n, 0);
	p = ft_looknegatif(&nbd, &nb, n);
	r = (char *)malloc((nbd + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[nbd] = '\0';
	if (p < 0)
		*r = '-';
	while ((nb / 10) > 0)
	{
		*(r + nbd - 1) = (char)((nb % 10) + 48);
		nb = nb / 10;
		nbd -= 1;
	}
	*(r + nbd - 1) = (char)((nb % 10) + 48);
	return (r);
}
