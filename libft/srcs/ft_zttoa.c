/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zttoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:29:51 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/17 16:44:36 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbdigit(size_t n, int nbd)
{
	if ((n / 10) != 0)
		return (ft_nbdigit(n / 10, nbd + 1));
	else
		return (nbd + 1);
}

char			*ft_zttoa(size_t n)
{
	int		nbd;
	char	*r;

	nbd = ft_nbdigit(n, 0);
	r = (char *)malloc((nbd + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[nbd] = '\0';
	while ((n / 10) > 0)
	{
		*(r + nbd - 1) = (char)((n % 10) + 48);
		n = n / 10;
		nbd -= 1;
	}
	*(r + nbd - 1) = (char)((n % 10) + 48);
	return (r);
}
