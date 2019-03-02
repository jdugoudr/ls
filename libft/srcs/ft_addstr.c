/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:28:38 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:08:37 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	more_one_one(char a, char b, char *s)
{
	int retenu;
	int r;

	r = (a + b) - 96;
	retenu = 0;
	if (r > 9)
	{
		retenu = 1;
		s[0] = (char)(r - 10 + 48);
	}
	else
		s[0] = (char)(r + 48);
	return (retenu);
}

static char	*do_last_one(int ret, size_t len, char *s)
{
	char	*res;

	if (ret)
	{
		if ((res = ft_strndup("1", len + 1)) == NULL)
		{
			free(s);
			return (NULL);
		}
		res = ft_strcat(res, s);
		free(s);
		return (res);
	}
	return (s);
}

static int	do_it_utility(char a, char b, char *res, int ret)
{
	int	ret_next;

	if (ret)
	{
		ret_next = more_one_one(a, b, res);
		if (more_one_one(res[0], '1', res) == 1)
			ret_next = 1;
	}
	else
		ret_next = more_one_one(a, b, res);
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
		ret = more_one_one(a[len_a - j], '1', &res[len_a - j]);
		j++;
	}
	while (j <= len_a)
	{
		res[len_a - j] = a[len_a - j];
		j++;
	}
	res[len_a] = '\0';
	return (do_last_one(ret, len_a, res));
}

char		*ft_addstr(char *a, char *b)
{
	size_t	len_a;
	size_t	len_b;
	char	*s;

	if (!a || !b)
		return (NULL);
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (len_a < len_b)
	{
		ft_swapstr(&a, &b);
		ft_swap(&len_a, &len_b);
	}
	s = do_it(a, b, len_a, len_b);
	return (s);
}
