/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:13:16 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 09:46:49 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l;
	char	*r;

	r = NULL;
	i = 0;
	l = 0;
	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	r = (char*)malloc((l + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	while (i < l)
	{
		*(r + i) = (*f)(i, *(s + i));
		i += 1;
	}
	*(r + i) = '\0';
	return (r);
}
