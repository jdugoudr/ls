/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:53:24 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:16:55 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"
#include <wchar.h>

int	manage_c(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if ((t->value = ft_strnew(1)) == NULL)
		error(ERR_STR, NULL);
	if (flags->fc & L_FLAG)
		t->value[0] = (char)va_arg(*ap, wint_t);
	else
		t->value[0] = (char)va_arg(*ap, int);
	return (run_flags(t, flags, tabf));
}
