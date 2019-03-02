/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:37:02 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 20:02:19 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (*(needle + i) != '\0' && *(haystack) != '\0' && i < len && len > 0)
	{
		if (*(haystack + i) == *(needle + i))
			i += 1;
		else
		{
			len -= 1;
			return (ft_strnstr((haystack + 1), needle, len));
		}
	}
	if (*(needle + i) == '\0')
		return ((char *)haystack);
	else
		return (NULL);
}
