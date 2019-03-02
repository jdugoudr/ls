/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:55:59 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:51:46 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_less(const char c, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == '-')
	{
		el->fc |= LS_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}
