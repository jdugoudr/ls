/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:08:01 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:05:32 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_tabf(t_fcfl tab[])
{
	int i;

	i = 0;
	while (i < NB_FLAGS)
	{
		if (i == 0)
			tab[i] = manage_point;
		else if (i == 1)
			tab[i] = manage_more;
		else if (i == 2)
			tab[i] = manage_diese;
		else if (i == 3)
			tab[i] = manage_minsize;
		else if (i == 4)
			tab[i] = manage_blank;
		i++;
	}
	return (i);
}

int		add_flag(const char c, const char *str, t_flags *flags, va_list *ap)
{
	int		nb_read;

	nb_read = 0;
	nb_read += init_blank(c, flags);
	nb_read += init_less(c, flags);
	nb_read += init_minisize(str, flags);
	nb_read += init_more(c, flags);
	nb_read += init_point(c, str, flags);
	nb_read += init_zero(c, flags);
	nb_read += init_l(c, str, flags);
	nb_read += init_ll(c, str, flags);
	nb_read += init_lll(c, flags);
	nb_read += init_hh(c, str, flags);
	nb_read += init_h(c, str, flags);
	nb_read += init_ds(c, flags);
	nb_read += init_z(c, flags);
	nb_read += init_j(c, flags);
	nb_read += init_star(c, str, flags, ap);
	if (nb_read == 0)
		error(ERR_FLAG, NULL);
	return (nb_read);
}

void	init_flags(t_flags *flags)
{
	flags->arg = NULL;
	flags->precision = NULL;
	flags->fc = NO_FLAG;
	flags->do_star = 0;
}
