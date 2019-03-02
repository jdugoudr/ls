/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbtoa_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:41:19 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:11:12 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*apro_value(char *s_mant, char *str_e, char *c)
{
	char	*tmp;

	if ((tmp = ft_faddstr(c, s_mant)) != NULL)
	{
		s_mant = ft_fmultistr(tmp, str_e);
		free(tmp);
	}
	if (tmp == NULL || s_mant == NULL)
		return (NULL);
	return (s_mant);
}

char		*mant_toa(unsigned long mant, char *mant_max, char *str_e, char *c)
{
	char	*s_mant;
	char	*tmp_mant;
	char	*tmp;
	char	*rest;

	rest = NULL;
	if ((tmp = ft_ultoa(mant)) == NULL)
		return (NULL);
	if (!(s_mant = ft_fdivstr(tmp, mant_max)))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	tmp_mant = s_mant;
	s_mant = apro_value(s_mant, str_e, c);
	free(tmp_mant);
	free(rest);
	return (s_mant);
}
