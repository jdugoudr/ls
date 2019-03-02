/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:22:23 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:18:07 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_it(char *a, char *b, char **i)
{
	char	*tmp;

	while (a && *i && ft_acmpi(a, b) >= 0)
	{
		tmp = a;
		a = ft_subtrackstr(a, b);
		free(tmp);
		tmp = *i;
		*i = ft_addstr(*i, "1");
		free(tmp);
	}
	if (!a || !(*i))
	{
		free(a);
		return (NULL);
	}
	return (a);
}

static char	*big_utility(char *r, char *b, size_t len_b, char **i)
{
	size_t	ii;
	size_t	len_a;
	char	*tmp;

	ii = 0;
	len_a = ft_strlen(b);
	while (r && ii < len_a - len_b)
	{
		tmp = *i;
		*i = ft_expstr(1, *i);
		free(tmp);
		tmp = r;
		r = ft_expstr(1, r);
		free(tmp);
		if (!r || !(*i))
		{
			free(r);
			return (NULL);
		}
		r = do_it(r, b, i);
		ii++;
	}
	return (r);
}

static char	*manage_big_nb(char *a, char *b, char **i)
{
	char	*tmp;
	char	*r;
	size_t	len_b;
	size_t	len_a;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if ((b = ft_expstr(len_a - len_b, b)) == NULL)
		return (NULL);
	r = do_it(a, b, i);
	r = big_utility(r, b, len_b, i);
	if (r && ft_strcmp(r, "0") != 0)
	{
		tmp = r;
		r = ft_strndup(r, ft_strlen(r) - (len_a - len_b));
		free(tmp);
	}
	if (!r)
		ft_strdel(i);
	free(b);
	return (r);
}

char		*ft_divstr(char *a, char *b, char **r)
{
	char	*u;
	char	*i;

	if (!a || !b)
		return (NULL);
	if (ft_acmpi(a, b) < 0)
	{
		*r = ft_strdup(a);
		return (ft_strdup("0"));
	}
	if ((u = ft_strdup(a)) == NULL)
		return (NULL);
	if ((i = ft_strdup("0")) != NULL)
		*r = manage_big_nb(u, b, &i);
	else
		free(u);
	return (i);
}
