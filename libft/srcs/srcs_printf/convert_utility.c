/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:41:48 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/22 15:17:33 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"

int		run_flags(t_convert *t, t_flags *flags, t_fcfl tabf[])
{
	int		i;

	i = 0;
	t->len = ft_strlen(t->value);
	if (t->c == 'c' && t->len == 0)
		t->len = 1;
	while ((flags->fc | NO_FLAG) && i < NB_FLAGS)
		tabf[i++](t, flags);
	return (t->len);
}

void	norm_hex(t_convert *t)
{
	char	*norm;

	t->len = t->len + 2;
	if ((norm = (char *)malloc((t->len + 1) * sizeof(char))) == NULL)
		error(ERR_STR, t->value);
	if (t->c == 'X')
		ft_strcpy(norm, "0X");
	else
		ft_strcpy(norm, "0x");
	ft_strcat(norm, t->value);
	free(t->value);
	t->value = norm;
}

void	norm_oct(t_convert *t)
{
	char	*norm;

	t->len = t->len + 1;
	if ((norm = (char *)malloc((t->len + 1) * sizeof(char))) == NULL)
		error(ERR_STR, t->value);
	ft_strcpy(norm, "0");
	ft_strcat(norm, t->value);
	free(t->value);
	t->value = norm;
}
