/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_point_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:22:32 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:01:52 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "flag_utility.h"

static char	*no_point(t_convert *t, char *norm, size_t nb_digit)
{
	if ((norm = ft_strndup(t->value, t->len + nb_digit + 1)) == NULL)
		error(ERR_STR, t->value);
	norm = ft_strcat(norm, ".");
	ft_strfill(norm + t->len + 1, '0', nb_digit);
	t->len += nb_digit + 1;
	return (norm);
}

static char	*appro(t_convert *t, char *dec_part, size_t nb)
{
	char	*tmp;
	char	*res;

	t->value[(dec_part - t->value) + nb] = '\0';
	if ((tmp = ft_strndup("0.", 2 + nb)) == NULL)
		error(ERR_STR, t->value);
	ft_strfill(tmp + 2, '0', nb - 1);
	tmp[nb + 1] = '1';
	if ((res = ft_faddstr(t->value, tmp)) == NULL)
	{
		free(tmp);
		error(ERR_STR, t->value);
	}
	free(tmp);
	t->len = ft_strlen(res);
	return (res);
}

static char	*one_point(t_convert *t, char *dpt, char *norm, size_t nb)
{
	size_t	i;

	i = 0;
	while (dpt[i] != '\0' && i < nb)
		i++;
	if (dpt[i] == '\0')
	{
		if ((norm = ft_strndup(t->value, t->len + nb - i)) == NULL)
			error(ERR_STR, t->value);
		ft_strfill(norm + t->len, '0', nb - i);
		t->len += nb - i;
	}
	else if (dpt[nb] < '5' || dpt[nb] == '\0' ||
			(dpt[nb] == '5' && !need_appro(dpt + nb + 1)))
	{
		if ((norm = ft_strndup(t->value, (dpt - t->value) + nb)) == NULL)
			error(ERR_STR, t->value);
		t->len = (dpt - t->value) + nb;
	}
	else
		norm = appro(t, dpt, nb);
	return (norm);
}

static char	*prec_zero(t_convert *t, char *dpt, char *norm)
{
	char	*tmp;

	if ((norm = ft_strndup(t->value, (dpt - 1 - t->value))) == NULL)
		error(ERR_STR, t->value);
	if (dpt[0] < '5' || dpt[0] == '\0')
		t->len = (dpt - t->value - 1);
	else
	{
		if ((tmp = ft_addstr(norm, "1")) == NULL)
		{
			free(norm);
			error(ERR_STR, t->value);
		}
		free(norm);
		norm = tmp;
		t->len = ft_strlen(norm);
	}
	return (norm);
}

char		*pt_for_f(t_convert *t, t_flags *el, char *norm, size_t *nb_digit)
{
	char	*dec_part;

	if (((t->value[0] < '0' || t->value[0] > '9') && t->value[0] != '-') ||
		(t->value[0] == '-' && (t->value[1] < '0' || t->value[1] > '9')))
	{
		if ((norm = ft_strdup(t->value)) == NULL)
			error(ERR_STR, t->value);
		return (norm);
	}
	dec_part = ft_strchr(t->value, '.');
	*nb_digit = ft_atoi(el->precision);
	if (!dec_part && *nb_digit == 0)
	{
		if ((norm = ft_strdup(t->value)) == NULL)
			error(ERR_STR, t->value);
		return (norm);
	}
	else if (!dec_part)
		return (no_point(t, norm, *nb_digit));
	else if (*nb_digit == 0)
		return (prec_zero(t, dec_part + 1, norm));
	else
		return (one_point(t, dec_part + 1, norm, *nb_digit));
}
