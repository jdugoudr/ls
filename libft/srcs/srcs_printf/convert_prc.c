/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:03:57 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:44:20 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

int	manage_prc(t_convert *t, t_flags *flags, va_list *ap)
{
	t_fcfl	tabf[NB_FLAGS];

	(void)ap;
	init_tabf(tabf);
	if ((t->value = ft_strdup("%")) == NULL)
		error(ERR_STR, NULL);
	return (run_flags(t, flags, tabf));
}
