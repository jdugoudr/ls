/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 21:51:03 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/06 13:29:24 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_expstr(size_t i, char *src)
{
	char	*s;
	size_t	len;

	if (!src)
		return (NULL);
	if (i == 0)
		return (ft_strdup(src));
	len = ft_strlen(src);
	if (len == 1 && src[0] == '0')
		return (ft_strdup(src));
	if ((s = ft_strndup(src, len + i)) == NULL)
		return (NULL);
	ft_strfill(s + len, '0', i);
	return (s);
}
