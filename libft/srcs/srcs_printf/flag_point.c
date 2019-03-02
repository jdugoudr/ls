/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:13:43 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:00:04 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "flag_utility.h"

int			init_point(const char c, const char *str, t_flags *el)
{
	int	nb_read;
	int	i;

	nb_read = 0;
	i = 0;
	if (c == '.')
	{
		i++;
		el->fc |= PR_FLAG;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if ((el->precision = ft_strndup(str + 1, i - 1)) == NULL)
			error(ERR_STR, NULL);
		nb_read += i;
	}
	return (nb_read);
}

static char	*pt_for_d(t_convert *t, t_flags *el, char *norm, size_t *nb_digit)
{
	*nb_digit = ft_atoi(el->precision);
	if (*nb_digit == 0 && ft_atoi(t->value) == 0)
	{
		if ((norm = ft_strdup("")) == NULL)
			error(ERR_STR, t->value);
		return (norm);
	}
	else if (*nb_digit == 0)
	{
		if ((norm = ft_strdup(t->value)) == NULL)
			error(ERR_STR, t->value);
		*nb_digit = t->len;
		return (norm);
	}
	if (t->value[0] == '-' || t->value[0] == '+')
		*nb_digit += 1;
	if (*nb_digit > t->len)
	{
		if ((norm = ft_strnew(*nb_digit)) == NULL)
			error(ERR_STR, t->value);
		filled_str(norm, '0', *nb_digit - t->len, t->value);
	}
	else if ((norm = ft_strdup(t->value)) == NULL)
		error(ERR_STR, t->value);
	return (norm);
}

static char	*pt_for_s(t_convert *t, t_flags *el, char *norm, size_t *nb_digit)
{
	(void)el;
	*nb_digit = ft_atoi(el->precision);
	if (*nb_digit >= t->len)
	{
		if ((norm = ft_strdup(t->value)) == NULL)
			error(ERR_STR, t->value);
		*nb_digit = t->len;
		return (norm);
	}
	else
	{
		if ((norm = ft_strndup(t->value, *nb_digit)) == NULL)
			error(ERR_STR, t->value);
		t->len = *nb_digit;
		return (norm);
	}
}

static char	*pt_for_x(t_convert *t, t_flags *el, char *norm, size_t *nb_digit)
{
	int	begin;

	begin = 0;
	*nb_digit = ft_atoi(el->precision);
	if (*nb_digit > t->len)
	{
		if ((norm = ft_strnew((*nb_digit))) == NULL)
			error(ERR_STR, t->value);
		ft_strncpy(norm, t->value, begin);
		filled_str(norm + begin, '0', *nb_digit - t->len, t->value + begin);
	}
	else
	{
		if (*nb_digit == 0 && ft_strcmp(t->value, "0") == 0)
		{
			if ((norm = ft_strdup("")) == NULL)
				error(ERR_STR, t->value);
			t->len = *nb_digit;
			return (norm);
		}
		*nb_digit = t->len;
		if ((norm = ft_strdup(t->value)) == NULL)
			error(ERR_STR, t->value);
	}
	return (norm);
}

void		manage_point(t_convert *t, t_flags *el)
{
	size_t	nb_digit;
	char	*norm;

	nb_digit = 0;
	norm = NULL;
	if ((el->fc & PR_FLAG) == 0 || t->value[0] == '%' || t->c == 'p' ||
			t->c == 'c')
		return ;
	if (t->c == 'x' || t->c == 'X' || t->c == 'o' || t->c == 'O')
		norm = pt_for_x(t, el, norm, &nb_digit);
	else if (t->c == 's')
		norm = pt_for_s(t, el, norm, &nb_digit);
	else if (t->c == 'f')
		norm = pt_for_f(t, el, norm, &nb_digit);
	else
		norm = pt_for_d(t, el, norm, &nb_digit);
	t->len = nb_print_for_point(t, nb_digit);
	free(t->value);
	t->value = norm;
}
