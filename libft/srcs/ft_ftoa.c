/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:09:16 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/12 11:13:12 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	ft_exp(int i)
{
	if (i > 0)
		return (ft_exp(i - 1) * 10);
	return (1);
}

static uintmax_t	dec_precision(double n, int precision, int more_pre)
{
	uintmax_t	nb_d;

	nb_d = (uintmax_t)((n - (uintmax_t)n) * ft_exp(precision + more_pre + 1));
	if (more_pre >= 1)
	{
		if (nb_d % 10 == 0 && more_pre == 10000)
			return (nb_d / ft_exp(more_pre + 1));
		else if (nb_d % 10 == 0)
			return (dec_precision(n, precision, more_pre + 1));
		else
		{
			ft_putnbr(nb_d % 10);
			return (nb_d / ft_exp(more_pre + 1) + 1);
		}
	}
	if (nb_d % 10 == 5)
		nb_d = dec_precision(n, precision, more_pre + 1);
	else
		nb_d = (nb_d / 10);
	return (nb_d);
}

static void			ft_fill_dec(uintmax_t n_d, char *s, int nbd_u, int nbd_d)
{
	int	j;

	j = nbd_d - 1;
	if (nbd_d == 0)
		return ;
	s[nbd_u] = '.';
	while (j > 0)
	{
		s[nbd_u + j] = (char)((n_d % 10) + 48);
		n_d = n_d / 10;
		j--;
	}
}

static char			*fill_s(uintmax_t n_u, int nbd_d, uintmax_t n_d, int p)
{
	char		*s;
	int			nbd_u;
	int			i;

	nbd_u = ft_nblen(n_u);
	i = nbd_u - 1;
	if ((s = ft_strnew(nbd_d + nbd_u + 1 + p)) == NULL)
		return (NULL);
	if (p > 0)
	{
		s[0] = '-';
		nbd_u += 1;
		i++;
	}
	if (nbd_d == 0 && n_d >= 1)
		n_u += 1;
	while (i >= p)
	{
		s[i] = (char)((n_u % 10) + 48);
		n_u = n_u / 10;
		i--;
	}
	ft_fill_dec(n_d, s, nbd_u, nbd_d);
	return (s);
}

char				*ft_ftoa(double n, int precision)
{
	int			nbd_d;
	uintmax_t	n_d;
	int			p;

	p = 0;
	nbd_d = 0;
	if ((((unsigned char *)&n)[sizeof(double) - 1]) & 0x80)
	{
		p = 1;
		n = -n;
	}
	n_d = dec_precision(n, precision, 0);
	if (precision > 0)
		nbd_d = ft_nblen(n_d);
	if (nbd_d > 0)
		nbd_d++;
	return (fill_s(n, nbd_d, n_d, p));
}
