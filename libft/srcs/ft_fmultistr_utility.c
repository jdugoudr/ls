/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmultistr_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:18:47 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:13:20 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*len_supp(char *nb, size_t len, size_t nb_dec_a, size_t nb_dec_b)
{
	char	*tmp;

	tmp = nb;
	if ((nb = ft_strndup(nb, len + 1)) == NULL)
		return (NULL);
	nb[len - (nb_dec_a + nb_dec_b)] = '.';
	nb[len - (nb_dec_a + nb_dec_b) + 1] = '\0';
	ft_strcat(nb, tmp + (len - (nb_dec_a + nb_dec_b)));
	return (nb);
}

static char	*len_inf(char *nb, size_t len, size_t nb_dec_a, size_t nb_dec_b)
{
	char	*tmp;

	tmp = nb;
	if ((nb = ft_strndup("0.", nb_dec_a + nb_dec_b + len + 2)) == NULL)
		return (NULL);
	ft_strfill(nb + 2, '0', nb_dec_a + nb_dec_b - len);
	ft_strcat(nb, tmp);
	return (nb);
}

char		*put_point(char *nb, size_t nb_dec_a, size_t nb_dec_b)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(nb);
	if (nb_dec_a + nb_dec_b == 0)
		return (ft_strdup(nb));
	if (len > nb_dec_a + nb_dec_b)
		tmp = len_supp(nb, len, nb_dec_a, nb_dec_b);
	else
		tmp = len_inf(nb, len, nb_dec_a, nb_dec_b);
	return (tmp);
}
