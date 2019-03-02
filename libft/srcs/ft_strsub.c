/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:13:12 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/25 22:24:06 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;

	r = NULL;
	if (s == NULL)
		return (NULL);
	r = ft_strnew(len);
	if (r == NULL)
		return (r);
	ft_strncpy(r, s + start, len);
	return (r);
}
