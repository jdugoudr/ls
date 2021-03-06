/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:44:11 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/09 20:01:12 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(intmax_t n, int nbd)
{
	if ((n / 10) != 0)
		return (ft_nbdigit(n / 10, nbd + 1));
	else
		return (nbd + 1);
}

static char	*ft_solver(int nbd, uintmax_t nb, int p)
{
	char	*r;

	r = (char *)malloc((nbd + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[nbd] = '\0';
	if (p < 0)
		r[0] = '-';
	while ((nb / 10) > 0)
	{
		*(r + nbd - 1) = (char)((nb % 10) + 48);
		nb = nb / 10;
		nbd -= 1;
	}
	*(r + nbd - 1) = (char)((nb % 10) + 48);
	return (r);
}

char		*ft_imaxtoa(intmax_t n)
{
	uintmax_t	nb;
	int			nbd;
	int			p;

	p = 1;
	nbd = ft_nbdigit(n, 0);
	if (n < 0)
	{
		p *= -1;
		nbd += 1;
	}
	nb = (uintmax_t)(n * p);
	return (ft_solver(nbd, nb, p));
}
