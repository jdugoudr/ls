/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:15 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 18:37:57 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long r;

	r = n;
	if (r < 0)
	{
		ft_putchar('-');
		r *= -1;
	}
	if ((r / 10) > 0)
	{
		ft_putnbr(r / 10);
		ft_putchar((r % 10) + 48);
	}
	else
		ft_putchar(r + 48);
}
