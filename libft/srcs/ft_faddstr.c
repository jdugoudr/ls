/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_faddstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:55:41 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:12:41 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	count_after_dec(char **nb)
{
	size_t	i;

	i = 0;
	if ((*nb = ft_strchr(*nb, '.')) != NULL)
	{
		while ((*nb)[i] != '\0')
			i++;
		i--;
	}
	if (nb != NULL && i != 0)
		*nb = ft_strdup(*nb + 1);
	else
		*nb = ft_strdup("0");
	return (i);
}

static char		*add_dec_part(char *a, char *b, char **rest, size_t size)
{
	char	*res;
	char	*tmp;

	if ((res = ft_addstr(a, b)) == NULL)
		return (NULL);
	if (ft_strlen(res) > size && size > 0)
	{
		tmp = res;
		res = ft_strdup(res + 1);
		free(tmp);
		*rest = "1";
	}
	else
		*rest = "0";
	return (res);
}

static char		*manage_dec(char *a, char *b, char **rest)
{
	size_t	len_a;
	size_t	len_b;
	char	*dec_tmp;
	char	*res;

	len_a = count_after_dec(&a);
	len_b = count_after_dec(&b);
	if (len_b > len_a)
	{
		ft_swapstr(&a, &b);
		ft_swap(&len_a, &len_b);
	}
	dec_tmp = b;
	if ((b = manage_dec_utility(a, b, len_a, len_b)) == NULL)
	{
		free(dec_tmp);
		return (NULL);
	}
	free(dec_tmp);
	res = add_dec_part(a, b, rest, len_a);
	free(a);
	free(b);
	return (res);
}

static char		*manage_uni(char *a, char *b, char *rest)
{
	char	*dec_a;
	char	*dec_b;
	char	*res;
	char	*tmp;

	if ((dec_a = ft_strchr(a, '.')) != NULL)
		a[dec_a - a] = '\0';
	if ((dec_b = ft_strchr(b, '.')) != NULL)
		b[dec_b - b] = '\0';
	if ((res = ft_addstr(a, b)) == NULL)
		return (NULL);
	if (rest[0] == '1')
	{
		tmp = res;
		res = ft_addstr(res, rest);
		free(tmp);
		if (res == NULL)
			return (NULL);
	}
	free(a);
	free(b);
	return (res);
}

char			*ft_faddstr(char *a, char *b)
{
	char	*res_dec;
	char	*res_uni;
	char	*res;
	char	*rest;
	size_t	len_dec;

	if (!a || !b || (res_dec = manage_dec(a, b, &rest)) == NULL)
		return (NULL);
	if ((res_uni = manage_uni(ft_strdup(a), ft_strdup(b), rest)) == NULL)
	{
		free(res_dec);
		return (NULL);
	}
	len_dec = ft_strlen(res_dec);
	len_dec > 0 ? len_dec += 1 : 0;
	res = ft_strndup(res_uni, ft_strlen(res_uni) + len_dec);
	if (res != NULL && len_dec != 0)
	{
		res = ft_strcat(res, ".");
		res = ft_strcat(res, res_dec);
	}
	free(res_dec);
	free(res_uni);
	return (res);
}
