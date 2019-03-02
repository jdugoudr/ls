/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:06:44 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/12/04 19:07:54 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		while (str[i] != '\0')
			i++;
		return ((char*)&str[i]);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
