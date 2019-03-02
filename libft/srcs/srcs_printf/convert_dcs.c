/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:27:29 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:38:48 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

int			manage_i(t_convert *t, t_flags *flags, va_list *ap)
{
	return (manage_d(t, flags, ap));
}

static void	d_continue(t_convert *t, t_flags *flags, va_list *ap)
{
	if (flags->fc & HH_FLAG)
	{
		if ((t->value = ft_itoa((char)va_arg(*ap, int))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & Z_FLAG)
	{
		if ((t->value = ft_szttoa(va_arg(*ap, ssize_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & J_FLAG)
	{
		if ((t->value = ft_imaxtoa(va_arg(*ap, intmax_t))) == NULL)
			error(ERR_STR, NULL);
	}
	else if ((t->value = ft_itoa(va_arg(*ap, int))) == NULL)
		error(ERR_STR, NULL);
}

int			manage_d(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if (flags->fc & L_FLAG)
	{
		if ((t->value = ft_ltoa(va_arg(*ap, long))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & LL_FLAG)
	{
		if ((t->value = ft_lltoa(va_arg(*ap, long long))) == NULL)
			error(ERR_STR, NULL);
	}
	else if (flags->fc & H_FLAG)
	{
		if ((t->value = ft_stoa(va_arg(*ap, int))) == NULL)
			error(ERR_STR, NULL);
	}
	else
		d_continue(t, flags, ap);
	return (run_flags(t, flags, tabf));
}

int			manage_s(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];
	char	*s;

	init_tabf(tabf);
	if ((s = va_arg(*ap, char *)) == NULL)
		s = "(null)";
	if ((t->value = ft_strdup(s)) == NULL)
		error(ERR_STR, NULL);
	return (run_flags(t, flags, tabf));
}
