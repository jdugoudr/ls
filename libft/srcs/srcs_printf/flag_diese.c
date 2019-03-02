/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:42:25 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:50:15 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_ds(const char c, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == '#')
	{
		el->fc |= DS_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}

void	manage_diese(t_convert *t, t_flags *el)
{
	if (t->c == '%' || t->c == 'd' || t->c == 'i' || t->c == 'u' ||
			t->c == 'U' || t->c == 'c' || t->c == 's' || t->c == 'f')
		return ;
	if (t->c == 'p')
		norm_hex(t);
	if ((el->fc & DS_FLAG) == 0)
		return ;
	else if (t->c == 'o' || t->c == 'O')
	{
		if (el->fc & PR_FLAG && t->value[0] == '0')
			return ;
		if (ft_atoi(t->value) != 0 ||
			(el->fc & PR_FLAG &&
			(el->precision[0] == '0' || el->precision[0] == '\0')))
			norm_oct(t);
	}
	else if (el->fc & PR_FLAG &&
			(ft_atoul_base(t->value, "0123456789abcdef") != 0 ||
			ft_atoul_base(t->value, "0123456789ABCDEF") != 0))
		norm_hex(t);
	else if ((el->fc & PR_FLAG) == 0 && ft_strcmp(t->value, "0") != 0)
		norm_hex(t);
}
