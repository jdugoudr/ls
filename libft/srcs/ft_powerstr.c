/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:32:35 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:14:53 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_it_pos(char *v, char *p)
{
	char	*tmp_v;
	char	*tmp_p;
	char	*result;

	tmp_p = p;
	if ((result = ft_strdup(v)) == NULL)
		return (NULL);
	tmp_v = result;
	while (ft_strcmp(p, "1") != 0)
	{
		if ((result = ft_multistr(result, v)) == NULL)
		{
			free(tmp_v);
			free(tmp_p);
			return (NULL);
		}
		free(tmp_v);
		p = ft_subtrackstr(p, "1");
		free(tmp_p);
		tmp_v = result;
		tmp_p = p;
	}
	free(tmp_p);
	return (result);
}

char		*ft_powerstr(char *value, char *power)
{
	char	*p;
	char	*tmp;
	int		neg;

	neg = 0;
	if (ft_strcmp(power, "0") == 0)
		return (ft_strdup("1"));
	if (power[0] == '-')
	{
		if ((p = ft_strdup(power + 1)) == NULL)
			return (NULL);
		neg = 1;
	}
	else if ((p = ft_strdup(power)) == NULL)
		return (NULL);
	tmp = do_it_pos(value, p);
	if (tmp && neg)
	{
		p = ft_fdivstr("1", tmp);
		free(tmp);
	}
	else
		p = tmp;
	return (p);
}
