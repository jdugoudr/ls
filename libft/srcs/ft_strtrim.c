/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:38:12 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/12 20:01:47 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	ss;
	size_t	se;
	char	*r;

	len = 0;
	ss = 0;
	se = 0;
	r = NULL;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (*(s + ss) == ' ' || *(s + ss) == '\n' || *(s + ss) == '\t')
		ss += 1;
	se = len;
	if (ss != len)
		while (*(s + se) == ' ' || *(s + se) == '\n' ||
				*(s + se) == '\t' || *(s + se) == '\0')
			se -= 1;
	r = ft_strnew(se - ss + 1);
	if (r == NULL)
		return (NULL);
	if (ss != len)
		ft_strncpy(r, s + ss, se - ss + 1);
	return (r);
}
