/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:53:35 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:09:02 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip(const char *str)
{
	int i;

	i = 0;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\v' ||
			*(str + i) == '\n' || *(str + i) == '\r' || *(str + i) == '\f')
		i += 1;
	return (i);
}

static int		ft_pos_in_base(const char *base, const char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0' && base[i] != c)
		i++;
	return (i);
}

unsigned long	ft_atoul_base(const char *str, const char *base)
{
	unsigned long	nb;
	int				i;
	int				len_base;

	i = ft_skip(str);
	nb = 0;
	len_base = ft_strlen(base);
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (ft_strchr(base, *(str + i)) != NULL && *(str + i) != '\0')
	{
		nb *= len_base;
		nb += (unsigned long)((ft_pos_in_base(base, *(str + i)) % len_base));
		i += 1;
	}
	return (nb);
}
