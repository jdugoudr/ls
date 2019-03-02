/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:21:46 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 18:39:44 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	r;

	r = n;
	if (r < 0)
	{
		ft_putchar_fd('-', fd);
		r *= -1;
	}
	if ((r / 10) > 0)
	{
		ft_putnbr_fd(r / 10, fd);
		ft_putchar_fd((r % 10) + 48, fd);
	}
	else
		ft_putchar_fd(r + 48, fd);
}
