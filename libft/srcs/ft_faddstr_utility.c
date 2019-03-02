/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:22:40 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/06 17:23:33 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*manage_dec_utility(char *a, char *b, size_t len_a, size_t len_b)
{
	char	*dec_tmp;

	if (len_a != len_b)
	{
		if ((dec_tmp = ft_strndup(b, len_a)) == NULL)
		{
			free(b);
			free(a);
			return (NULL);
		}
		ft_strfill(dec_tmp + len_b, '0', len_a - len_b);
		return (dec_tmp);
	}
	return (ft_strdup(b));
}
