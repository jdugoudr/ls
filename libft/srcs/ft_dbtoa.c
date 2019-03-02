/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:03:07 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:10:33 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dbtoa.h"

static char			*do_neg(char *s_mant)
{
	char	*tmp;

	tmp = s_mant;
	if ((s_mant = ft_strndup("-", 1 + ft_strlen(s_mant))))
		s_mant = ft_strcat(s_mant, tmp);
	free(tmp);
	return (s_mant);
}

static char			*calcul_value(unsigned int exp, unsigned long mant)
{
	char	*tmp;
	char	*str_e;
	char	*s_mant;

	s_mant = NULL;
	tmp = NULL;
	str_e = NULL;
	if ((tmp = ft_itoa(exp - EXP_SHI)) == NULL)
		return (NULL);
	str_e = ft_powerstr("2", tmp);
	free(tmp);
	if (str_e)
	{
		if (exp == 0)
			s_mant = mant_toa(mant, MAT_MAX, str_e, "0");
		else
			s_mant = mant_toa(mant, MAT_MAX, str_e, "1");
	}
	free(str_e);
	return (s_mant);
}

static char			*check_norm(int sign, unsigned int exp, unsigned long mant)
{
	char	*s_mant;

	s_mant = NULL;
	if (exp == EXP_MAX)
	{
		if (mant == 0)
			s_mant = ft_strdup("inf");
		else
			return (ft_strdup("NaN"));
	}
	else if (exp == 0 && mant == 0)
		s_mant = ft_strdup("0");
	else
		s_mant = calcul_value(exp, mant);
	if (sign && s_mant)
		s_mant = do_neg(s_mant);
	return (s_mant);
}

static unsigned int	extr_exp(unsigned char *ptr, int shift, unsigned int exp)
{
	int i;

	i = shift;
	while (i > 0)
	{
		exp += ptr[i - 1];
		exp = exp << 8;
		i--;
	}
	exp = exp >> 12;
	return (exp);
}

char				*ft_dbtoa(double f)
{
	int				sign;
	unsigned int	exp;
	unsigned long	mant;
	unsigned char	*ptr;

	ptr = (unsigned char *)&f;
	sign = 0;
	exp = 0;
	mant = 0;
	sign |= ptr[(NBR_BIT / 8) - 1] & 0x80;
	if (SZE_EXP % 2)
		exp = extr_exp(ptr + (NBR_BIT / 8) - ((SZE_EXP / 8) + 1), 2, exp);
	else
		exp = extr_exp(ptr + (NBR_BIT / 8) - (SZE_EXP / 8), 2, exp);
	exp &= EXP_MAX;
	mant |= (*(unsigned long *)&f & MAS_MAT);
	return (check_norm(sign, exp, mant));
}
