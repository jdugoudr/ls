/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:44:56 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/11/10 16:35:23 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != '\0')
		return (ft_strcmp(s1 + 1, s2 + 1));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
