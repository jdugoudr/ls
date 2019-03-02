/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdivstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:40:19 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/06 13:46:22 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*do_it(char *a, char *b, size_t *i)
{
	char	*rest;
	char	*tmp_a;
	char	*tmp;
	size_t	ii;

	ii = 0;
	rest = NULL;
	if (a == NULL)
		return (NULL);
	tmp_a = ft_divstr(a, b, &rest);
	while (ft_strcmp(rest, "0") != 0 && tmp_a && ii < 1638)
	{
		free(rest);
		free(tmp_a);
		ii += 1;
		tmp_a = ft_expstr(ii, a);
		tmp = tmp_a;
		tmp_a = ft_divstr(tmp_a, b, &rest);
		free(tmp);
	}
	free(a);
	free(rest);
	*i += ii;
	return (tmp_a);
}

static char	*norm(char *nb, size_t i)
{
	char	*tmp;

	if (i == 0)
		return (ft_strdup(nb));
	tmp = put_point(nb, i, 0);
	return (tmp);
}

static char	*opti(char *a, char *b, size_t *i)
{
	size_t	len_a;
	size_t	len_b;
	char	*tmp;

	tmp = a;
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (len_a < len_b)
	{
		tmp = ft_strndup(a, len_b);
		ft_strfill(tmp + len_a, '0', len_b - len_a);
		*i = len_b - len_a;
		free(a);
	}
	else if (len_a == len_b && a[0] < b[0])
	{
		tmp = ft_strndup(a, len_a + 1);
		ft_strfill(tmp + len_a, '0', 1);
		*i += 1;
		free(a);
	}
	return (tmp);
}

char		*ft_fdivstr(char *a, char *b)
{
	size_t	i;
	char	*res;
	char	*tmp;

	i = 0;
	res = NULL;
	if (!a || !b || b[0] == 0)
		return (NULL);
	if (a[0] == '0')
		return (ft_strdup(a));
	tmp = opti(ft_strdup(a), b, &i);
	tmp = do_it(tmp, b, &i);
	if (tmp)
	{
		if (i == 0)
			res = tmp;
		else
		{
			res = norm(tmp, i);
			free(tmp);
		}
	}
	return (res);
}
