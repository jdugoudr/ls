/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:15:12 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/26 15:59:38 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabsort(char **tab, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 1;
	j = i;
	while (i < len)
	{
		tmp = tab[i];
		while (j > 0 && ft_strcmp(tab[j - 1], tmp) > 0)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
		j = i;
	}
	return (tab);
}
