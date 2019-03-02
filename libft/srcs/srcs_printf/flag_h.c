/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:26:54 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/18 10:51:53 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int	init_h(const char c, const char *str, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == 'h' && str[1] != 'h')
	{
		el->fc |= H_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}
