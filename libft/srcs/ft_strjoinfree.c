/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:49:39 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/17 16:49:52 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char **str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buff);
	ft_strdel(str);
	return (tmp);
}
