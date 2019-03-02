/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minisize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:03:42 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 08:57:10 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "flag_utility.h"

int			init_minisize(const char *str, t_flags *el)
{
	int	nb_read;
	int	i;

	nb_read = 0;
	i = 0;
	if (str[i] > '0' && str[i] <= '9')
	{
		el->fc |= MS_FLAG;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if ((el->arg = ft_strndup(str, i)) == NULL)
			error(ERR_STR, NULL);
		nb_read += i;
	}
	return (nb_read);
}

static void	avoid_hex(t_convert *t, size_t nb_digit, char *norm)
{
	if (t->value[2] == '\0')
		filled_str(norm, '0', nb_digit - t->len, t->value);
	else
	{
		ft_strncpy(norm, t->value, 2);
		filled_str(norm + 2, '0', nb_digit - t->len, t->value + 2);
	}
}

static int	do_it(t_convert *t, t_flags *el, size_t nb_digit, char c)
{
	char	*norm;

	if ((norm = ft_strnew(nb_digit)) == NULL)
		error(ERR_STR, t->value);
	if ((t->c == 'p' ||
		((t->c == 'x' || t->c == 'X') && el->fc & DS_FLAG)) &&
		c == '0')
		avoid_hex(t, nb_digit, norm);
	else if ((el->fc & LS_FLAG) == 0)
		filled_str(norm, c, nb_digit - t->len, t->value);
	else
	{
		ft_strcat(norm, t->value);
		filled_frback(norm + t->len, ' ', nb_digit - t->len);
	}
	free(t->value);
	t->value = norm;
	return (nb_digit);
}

void		manage_minsize(t_convert *t, t_flags *el)
{
	size_t	nb_digit;
	char	c;

	if ((el->fc & MS_FLAG) == 0)
		return ;
	c = ' ';
	if ((el->fc & ZR_FLAG && (el->fc & LS_FLAG) == 0) &&
			((el->fc & PR_FLAG) == 0 || t->c == 'f'))
		c = '0';
	nb_digit = ft_atoi(el->arg);
	if (el->fc & BL_FLAG && t->c != '%')
		nb_digit--;
	if (nb_digit > t->len)
		t->len = do_it(t, el, nb_digit, c);
}
