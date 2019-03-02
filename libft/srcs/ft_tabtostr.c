/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:58:52 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/19 11:55:05 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabtostr(const char **tab)
{
	char	*s;
	int		len;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (tab == NULL)
		return (NULL);
	len = ft_tablen(tab);
	while (i < len)
	{
		size += ft_strlen(*tab);
		i++;
	}
	s = ft_strnew(size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ft_strcat(s, *(tab + i));
		i++;
	}
	return (s);
}
