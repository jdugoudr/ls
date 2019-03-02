/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:05:30 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/12 11:13:13 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

int	manage_f(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl		tabf[NB_FLAGS];
	int			precision;

	init_tabf(tabf);
	if (flags->fc & PR_FLAG)
		precision = ft_atoi(flags->precision);
	else
	{
		precision = 6;
		flags->fc |= PR_FLAG;
		flags->precision = ft_strdup("6");
	}
	if (flags->fc & LLL_FLAG)
	{
		if ((t->value = ft_ldbtoa(va_arg(*ap, long double))) == NULL)
			error(ERR_STR, NULL);
	}
	else
	{
		if ((t->value = ft_dbtoa(va_arg(*ap, double))) == NULL)
			error(ERR_STR, NULL);
	}
	return (run_flags(t, flags, tabf));
}
