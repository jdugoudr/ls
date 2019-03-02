/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_lll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:46:06 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:52:17 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		init_lll(const char c, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == 'L')
	{
		el->fc |= LLL_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}
