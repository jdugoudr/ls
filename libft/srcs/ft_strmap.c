/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:47:54 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/11 18:43:26 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	l;
	char	*r;

	r = NULL;
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	l = ft_strlen(s);
	r = (char*)malloc((l + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	while (i < l)
	{
		*(r + i) = (*f)(*(s + i));
		i += 1;
	}
	*(r + i) = '\0';
	return (r);
}
