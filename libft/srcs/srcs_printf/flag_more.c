/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:48:37 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:57:32 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "flag_utility.h"

int		init_more(const char c, t_flags *el)
{
	int	nb_read;

	nb_read = 0;
	if (c == '+')
	{
		el->fc |= MR_FLAG;
		nb_read += 1;
	}
	return (nb_read);
}

void	manage_more(t_convert *t, t_flags *el)
{
	char	*normalize;
	size_t	len;

	if ((el->fc & MR_FLAG) == 0 || t->c == '%' || t->c == 'p' ||
		t->c == 'x' || t->c == 'X' || t->c == 'u' || t->c == 'U')
		return ;
	if (t->value[0] == '-')
		return ;
	len = t->len + 1;
	if ((normalize = ft_strnew(len)) == NULL)
		error(ERR_STR, t->value);
	if (t->value[0] == '-')
		filled_str(normalize, '-', 1, t->value);
	else
		filled_str(normalize, '+', 1, t->value);
	t->len = len;
	free(t->value);
	t->value = normalize;
}
