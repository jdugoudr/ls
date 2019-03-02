/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:36:10 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/06 13:45:02 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbdigit(unsigned long n, long nbd)
{
	if ((n / 10) != 0)
		return (ft_nbdigit(n / 10, nbd + 1));
	else
		return (nbd + 1);
}

char			*ft_ultoa(unsigned long nb)
{
	int		nbd;
	char	*r;

	nbd = ft_nbdigit(nb, 0);
	r = (char *)malloc((nbd + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[nbd] = '\0';
	while ((nb / 10) > 0)
	{
		*(r + nbd - 1) = (char)((nb % 10) + 48);
		nb = nb / 10;
		nbd -= 1;
	}
	*(r + nbd - 1) = (char)((nb % 10) + 48);
	return (r);
}
