/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmultistr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:35:15 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:13:03 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_after_dec(char *nb)
{
	size_t	i;

	i = 0;
	if ((nb = ft_strchr(nb, '.')) != NULL)
	{
		while (nb[i] != '\0')
			i++;
		i--;
	}
	return (i);
}

static char		*remove_zero(char *nb)
{
	size_t	i;

	i = 0;
	while (nb[i] == '0')
		i++;
	if (nb[i] == '\0')
		return (ft_strdup("0"));
	return (ft_strdup(nb + i));
}

static char		*shift_str(char *nb, size_t *i)
{
	size_t	ii;
	char	*nb_shi;
	char	*tmp;

	*i = count_after_dec(nb);
	ii = 0;
	if (*i == 0)
	{
		if ((nb_shi = ft_strchr(nb, '.')) != NULL)
			nb[0] = '\0';
	}
	else
	{
		nb_shi = ft_strchr(nb, '.');
		while (ii < *i)
		{
			nb_shi[ii] = nb_shi[ii + 1];
			ii++;
		}
		nb_shi[*i] = '\0';
	}
	tmp = remove_zero(nb);
	free(nb);
	return (tmp);
}

char			*ft_fmultistr(char *a, char *b)
{
	size_t	nb_dec_a;
	size_t	nb_dec_b;
	char	*new_a;
	char	*new_b;
	char	*res;

	new_a = ft_strdup(a);
	if (!new_a || !(new_b = ft_strdup(b)))
	{
		free(new_a);
		return (NULL);
	}
	new_a = shift_str(new_a, &nb_dec_a);
	new_b = shift_str(new_b, &nb_dec_b);
	res = ft_multistr(new_a, new_b);
	free(new_a);
	free(new_b);
	if (res == NULL)
		return (NULL);
	new_a = res;
	res = put_point(res, nb_dec_a, nb_dec_b);
	free(new_a);
	return (res);
}
