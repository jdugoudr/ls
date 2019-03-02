/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:54:24 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:50:50 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int	init_hh(const char c, const char *str, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == 'h' && str[1] == 'h')
	{
		el->fc |= HH_FLAG;
		nb_read += 2;
	}
	return (nb_read);
}
