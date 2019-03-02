/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:50:05 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/24 14:15:08 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = NULL;
	p = malloc(size * sizeof(char));
	if (p == NULL)
		return (p);
	else
	{
		ft_bzero(p, size);
		return (p);
	}
}
