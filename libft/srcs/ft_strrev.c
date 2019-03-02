/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:00:55 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/01 16:08:46 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strrev(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	len--;
	while (i < len)
	{
		ft_swapstr(tab + i, tab + len);
		i++;
		len--;
	}
	return (tab);
}
