/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:52:34 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:04:06 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_zero(const char c, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == '0')
	{
		el->fc |= ZR_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}
