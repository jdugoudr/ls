/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:33:46 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 20:01:06 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	while (*(needle + i) != '\0' && *(haystack) != '\0')
	{
		if (*(haystack + i) == *(needle + i))
			i += 1;
		else
			return (ft_strstr((haystack + 1), needle));
	}
	if (*(needle + i) == '\0')
		return ((char *)haystack);
	else
		return (NULL);
}
