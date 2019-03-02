/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:35:51 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:41:50 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

static void	more_lenght_modifier(t_convert *t, t_flags *flags, va_list *ap)
{
	if (flags->fc & H_FLAG)
	{
		if ((t->value = ft_ustoa_oct(va_arg(*ap, unsigned int))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & HH_FLAG)
	{
		if ((t->value = ft_uctoa_oct(va_arg(*ap, unsigned int))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & J_FLAG)
	{
		if ((t->value = ft_uimaxtoa_oct(va_arg(*ap, uintmax_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & Z_FLAG)
	{
		if ((t->value = ft_zttoa_oct(va_arg(*ap, size_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if ((t->value = ft_uitoa_oct(va_arg(*ap, unsigned int))) == NULL)
		error(ERR_STR, NULL);
}

int			manage_o(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if (flags->fc & L_FLAG)
	{
		if ((t->value = ft_ultoa_oct(va_arg(*ap, unsigned long))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & LL_FLAG)
	{
		if ((t->value = ft_ulltoa_oct(va_arg(*ap, unsigned long long))) == NULL)
			error(ERR_STR, NULL);
	}
	else
		more_lenght_modifier(t, flags, ap);
	return (run_flags(t, flags, tabf));
}

int			manage_oo(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if ((t->value = ft_ultoa_oct(va_arg(*ap, unsigned long))) == NULL)
		error(ERR_STR, NULL);
	return (run_flags(t, flags, tabf));
}
