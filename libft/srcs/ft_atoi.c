/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:42:35 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/12 15:42:31 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip(const char *str)
{
	int i;

	i = 0;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\v' ||
			*(str + i) == '\n' || *(str + i) == '\r' || *(str + i) == '\f')
		i += 1;
	return (i);
}

int			ft_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				signe;

	signe = 1;
	i = ft_skip(str);
	nb = 0;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			signe = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		nb = (nb * 10) + (long long int)(*(str + i) - 48);
		i += 1;
	}
	return ((int)nb * signe);
}
