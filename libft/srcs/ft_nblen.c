/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:08:34 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/16 10:20:32 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_nblen(intmax_t n)
{
	uintmax_t	i;
	uintmax_t	nb;

	i = 1;
	if (n < 0)
		nb = -(uintmax_t)n;
	else
		nb = (uintmax_t)n;
	while ((nb / 10) > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
