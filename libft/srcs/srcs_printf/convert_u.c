/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:12:18 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:45:33 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

static void	more_lenght_modifier(t_convert *t, t_flags *flags, va_list *ap)
{
	if (flags->fc & H_FLAG)
	{
		if ((t->value = ft_ustoa(va_arg(*ap, unsigned int))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & HH_FLAG)
	{
		if ((t->value = ft_uctoa(va_arg(*ap, unsigned int))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & J_FLAG)
	{
		if ((t->value = ft_uimaxtoa(va_arg(*ap, uintmax_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & Z_FLAG)
	{
		if ((t->value = ft_zttoa(va_arg(*ap, size_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if ((t->value = ft_uitoa(va_arg(*ap, unsigned int))) == NULL)
		error(ERR_STR, NULL);
}

int			manage_u(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if (flags->fc & L_FLAG)
	{
		if ((t->value = ft_ultoa(va_arg(*ap, unsigned long))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & LL_FLAG)
	{
		if ((t->value = ft_ulltoa(va_arg(*ap, unsigned long long))) == NULL)
			error(ERR_STR, NULL);
	}
	else
		more_lenght_modifier(t, flags, ap);
	return (run_flags(t, flags, tabf));
}

int			manage_uu(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if ((t->value = ft_ultoa(va_arg(*ap, unsigned long))) == NULL)
		error(ERR_STR, NULL);
	return (run_flags(t, flags, tabf));
}
