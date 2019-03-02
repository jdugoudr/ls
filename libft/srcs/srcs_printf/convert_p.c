/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:14:18 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:42:29 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

int	manage_p(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if ((t->value = ft_ltoa_hex(va_arg(*ap, long))) == NULL)
		error(ERR_STR, NULL);
	t->len = ft_strlen(t->value);
	if ((flags->fc | NO_FLAG) == 0)
		norm_hex(t);
	return (run_flags(t, flags, tabf));
}
