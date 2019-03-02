/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:03:18 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:51:23 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_l(const char c, const char *str, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == 'l' && str[1] != 'l')
	{
		el->fc |= L_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}
