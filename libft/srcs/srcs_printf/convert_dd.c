/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:14:04 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:39:37 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

int	manage_dd(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	init_tabf(tabf);
	if ((t->value = ft_ltoa(va_arg(*ap, long))) == NULL)
		error(ERR_STR, NULL);
	return (run_flags(t, flags, tabf));
}
