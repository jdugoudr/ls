/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:00:26 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:03:39 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_utility.h"

static char	*filled_wh_zero(char *str, char c, int nb, char *src)
{
	int	i;
	int	is_sign;

	is_sign = 0;
	i = 0;
	if (c == '0')
	{
		if (src[0] == '-')
			str[0] = '-';
		else
			str[0] = '+';
		i++;
		nb++;
		is_sign = 1;
	}
	while (i < nb)
		str[i++] = c;
	return (src + is_sign);
}

void		filled_str(char *str, char c, int nb, char *src)
{
	int	i;

	i = 0;
	if (src[0] == '-' || src[0] == '+')
		ft_strcat(str, (filled_wh_zero(str, c, nb, src)));
	else
	{
		while (i < nb)
			str[i++] = c;
		ft_strcat(str, src);
	}
}

void		filled_frback(char *str, char c, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
}

int			nb_print_for_point(t_convert *t, size_t nb_digit)
{
	if ((t->c == 'd' || t->c == 'i' || t->c == 'u' || t->c == 'U') &&
			(t->value[0] == '0' && nb_digit == 0))
	{
		return (0);
	}
	else if (nb_digit > t->len)
		return (nb_digit);
	return (t->len);
}

int			need_appro(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] > '0')
			return (1);
		i++;
	}
	return (0);
}
