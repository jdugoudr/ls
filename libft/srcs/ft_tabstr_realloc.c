/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:06:11 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/27 16:16:04 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabstr_realloc(char **tab, int old_size, int new_size)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = (char **)malloc(new_size * sizeof(char *));
	while (i < old_size)
	{
		new_tab[i] = tab[i];
		i++;
	}
	free(tab);
	while (i < new_size)
	{
		new_tab[i] = NULL;
		i++;
	}
	new_tab[new_size - 1] = NULL;
	return (new_tab);
}
