/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:16:19 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/05 23:06:16 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

static void	print_number(const unsigned char *addr, size_t size, size_t i)
{
	int a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ft_putnbr_hex(*(addr + i + a), 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
	while (a < 16)
	{
		write(1, "  ", 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
}

void		ft_memprint(const void *addr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		print_number((const unsigned char *)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}
