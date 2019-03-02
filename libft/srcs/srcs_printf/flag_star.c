/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:27:26 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:02:51 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int	init_star(const char c, const char *str, t_flags *el, va_list *ap)
{
	char	*new_arg;
	int		nb_read;

	nb_read = 0;
	if (c == '*')
	{
		nb_read += 1;
		if ((new_arg = ft_zttoa(va_arg(*ap, size_t))) == NULL)
			error(ERR_STR, NULL);
		if (*(str - 1) == '.')
			el->precision = new_arg;
		else
		{
			el->fc |= MS_FLAG;
			el->arg = new_arg;
		}
	}
	return (nb_read);
}
