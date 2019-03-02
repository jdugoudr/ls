/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:42:40 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:14:22 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*multiple_one(char *a, char b)
{
	int		i;
	char	*tmp;
	char	*tmp_s;

	i = 0;
	tmp = ft_strdup("0");
	while (i < b - 48 && b != '0' && tmp)
	{
		tmp_s = tmp;
		tmp = ft_addstr(tmp, a);
		free(tmp_s);
		i++;
	}
	if (!tmp)
		return (NULL);
	return (tmp);
}

static char	*do_it_utility(char *s, char *ret, size_t i)
{
	size_t	len;
	char	*tmp;

	tmp = s;
	s = ft_addstr(ret, s);
	free(tmp);
	if (s && i > 1)
	{
		len = ft_strlen(s);
		tmp = s;
		s = ft_strndup(s, len + 1);
		free(tmp);
		ft_strfill(s + len, '0', 1);
	}
	else if (!s)
		return (NULL);
	return (s);
}

static char	*do_it(char *a, char *b, char *s, size_t len_b)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	i = 0;
	ret = NULL;
	while (i < len_b)
	{
		tmp = ret;
		ret = multiple_one(a, b[i]);
		free(tmp);
		if (ret)
			s = do_it_utility(s, ret, len_b - i);
		if (!ret || !s)
		{
			free(ret);
			free(s);
			return (NULL);
		}
		i++;
	}
	free(ret);
	return (s);
}

char		*ft_multistr(char *a, char *b)
{
	size_t	len_a;
	size_t	len_b;
	char	*s;

	if (!a || !b)
		return (NULL);
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (ft_strcmp(a, "0") == 0 || ft_strcmp(b, "0") == 0)
		return (ft_strdup("0"));
	if (len_a < len_b)
	{
		ft_swap(&len_a, &len_b);
		ft_swapstr(&a, &b);
	}
	if ((s = ft_strdup("0")) == NULL)
		return (NULL);
	s = do_it(a, b, s, len_b);
	return (s);
}
