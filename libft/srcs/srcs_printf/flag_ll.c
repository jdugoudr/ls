/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:46:06 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/18 10:51:20 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_ll(const char c, const char *str, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == 'l' && str[1] == 'l')
	{
		el->fc |= LL_FLAG;
		nb_read += 2;
	}
	return (nb_read);
}
