/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_blank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:24:02 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:49:29 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "flag_utility.h"

int		init_blank(const char c, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == ' ')
	{
		el->fc |= BL_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}

void	manage_blank(t_convert *t, t_flags *el)
{
	char	*normalize;
	size_t	len;

	if ((el->fc & BL_FLAG) == 0 || (el->fc & MR_FLAG) != 0 ||
			t->value[0] == '%' || t->c == 'p' || t->c == 'x' || t->c == 'c' ||
			t->c == 'u' || t->c == 'U')
		return ;
	if (t->value[0] == '-')
		return ;
	len = ft_strlen(t->value) + 1;
	if ((normalize = ft_strnew(len)) == NULL)
		error(ERR_STR, t->value);
	filled_str(normalize, ' ', 1, t->value);
	t->len = len;
	free(t->value);
	t->value = normalize;
}
