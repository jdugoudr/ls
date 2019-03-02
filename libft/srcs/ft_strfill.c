/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:02:49 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/02 13:44:05 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *str, char c, size_t len)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
