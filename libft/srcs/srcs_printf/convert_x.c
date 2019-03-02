/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:03:34 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:48:22 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

static void	x_utility(t_convert *t, t_flags *flags, va_list *ap)
{
	if (flags->fc & L_FLAG)
	{
		if ((t->value = ft_ultoa_hex(va_arg(*ap, unsigned long))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & Z_FLAG)
	{
		if ((t->value = ft_zttoa_hex(va_arg(*ap, size_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & LL_FLAG)
	{
		if ((t->value = ft_ulltoa_hex(va_arg(*ap, unsigned long long))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & J_FLAG)
	{
		if ((t->value = ft_uimaxtoa_hex(va_arg(*ap, uintmax_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if ((t->value = ft_uitoa_hex(va_arg(*ap, unsigned int))) == NULL)
		error(ERR_STR, NULL);
	t->len = ft_strlen(t->value);
}

int			manage_x(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	x_utility(t, flags, ap);
	return (run_flags(t, flags, tabf));
}

int			manage_xx(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	x_utility(t, flags, ap);
	ft_strtoupper(t->value);
	return (run_flags(t, flags, tabf));
}
