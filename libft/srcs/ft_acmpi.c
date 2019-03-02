/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acmpi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:08:29 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/20 15:24:16 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_acmpi(const char *s1, const char *s2)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_strlen(s1);
	len_b = ft_strlen(s2);
	if (len_a > len_b)
		return (1);
	else if (len_a < len_b)
		return (-1);
	else
		return (ft_strcmp(s1, s2));
}
