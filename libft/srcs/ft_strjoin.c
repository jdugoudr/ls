/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:07:00 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/27 14:07:27 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_doit(char const *s1, char const *s2, char *dest)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s1[j] != '\0')
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		dest = ft_doit(s1, s2, dest);
		return (dest);
	}
	return ((char *)s1);
}
