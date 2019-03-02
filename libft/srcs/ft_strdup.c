/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:07:29 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/12/04 19:07:31 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (!(dest = (char*)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
