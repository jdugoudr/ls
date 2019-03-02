/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:22:36 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/10 13:33:39 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
		else
			i -= 1;
	}
	if (*(s + i) == c)
		return ((char *)(s + i));
	else
		return (NULL);
}
