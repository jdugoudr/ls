/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:00:12 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/14 17:28:19 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbdigit(int n, int nbd)
{
	if ((n / 10) != 0)
		return (ft_nbdigit(n / 10, nbd + 1));
	else
		return (nbd + 1);
}

static int		ft_looknegatif(int *nbd, long *nb)
{
	int	p;

	p = 1;
	if (*nb < 0)
	{
		p *= -1;
		*nbd += 1;
		*nb *= -1;
	}
	return (p);
}

char			*ft_itoa(int n)
{
	long	nb;
	int		nbd;
	char	*r;
	int		p;

	p = 1;
	nbd = ft_nbdigit(n, 0);
	nb = n;
	p = ft_looknegatif(&nbd, &nb);
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
