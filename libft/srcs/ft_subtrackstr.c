/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtrackstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:28:44 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/04 19:45:04 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_last_one(size_t len, char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	while (i < len && s[i] == '0')
		i++;
	if (i == len)
		res = ft_strdup("0");
	else
		res = ft_strndup(s + i, len - i);
	free(s);
	return (res);
}

static int	do_it_utility(char a, char b, char *res, int ret)
{
	int	ret_next;

	ret_next = 0;
	if (a >= b + ret)
		res[0] = a - (b + ret) + 48;
	else
	{
		ret_next = 1;
		res[0] = (a + 10) - (b + ret) + 48;
	}
	return (ret_next);
}

static char	*do_it(char *a, char *b, size_t len_a, size_t len_b)
{
	int		ret;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	ret = 0;
	if ((res = malloc((len_a + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (i++ < len_b)
		ret = do_it_utility(a[len_a - i], b[len_b - i], &res[len_a - i], ret);
	j = i;
	while (j <= len_a && ret)
	{
		ret = do_it_utility(a[len_a - j], '1', &res[len_a - j], 0);
		j++;
	}
	while (j <= len_a)
	{
		res[len_a - j] = a[len_a - j];
		j++;
	}
	res[len_a] = '\0';
	return (do_last_one(len_a, res));
}

static char	*check_less(int neg, char *s)
{
	char	*res;

	if (neg == 0 || s == NULL)
		return (s);
	res = ft_strndup("-", ft_strlen(s) + 1);
	res = ft_strcat(res, s);
	free(s);
	return (res);
}

char		*ft_subtrackstr(char *a, char *b)
{
	size_t	len_a;
	size_t	len_b;
	char	*s;
	int		neg;

	neg = 0;
	if (ft_acmpi(a, b) == 0)
		return (ft_strdup("0"));
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (ft_acmpi(a, b) < 0)
	{
		neg = 1;
		ft_swapstr(&a, &b);
		ft_swap(&len_a, &len_b);
	}
	s = do_it(a, b, len_a, len_b);
	return (check_less(neg, s));
}
