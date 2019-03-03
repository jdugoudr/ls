/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 10:55:33 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/03 17:11:35 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
 ** We sort params array by time if flag t is present
 ** or by name if it's not.
*/
static t_params	*sort_rev_params(t_params *t, short flag)
{
	t_params	tmp;
	int			i;
	int			j;

	i = 1;
	j = 1;
	while (t[i].is_last)
	{
		ft_memcpy(&tmp, t + i, sizeof(t_params));
		while (j > 0 &&
				(((flag & T_FLAG) && t[j - 1].time > tmp.time) ||
				(!(flag & T_FLAG) && ft_strcmp(t[j - 1].name, tmp.name) < 0)))
		{
			ft_memcpy(t + j, t + (j - 1), sizeof(t_params));
			j--;
		}
		ft_memcpy(t + j, &tmp, sizeof(t_params));
		i++;
		j = i;
	}
	return (t);
}

t_params	*sort_params_st(t_params *t, short flag)
{
	t_params	tmp;
	int			i;
	int			j;

	i = 1;
	j = 1;
	if (!t || t[0].is_last == 0)
		return (t);
	if (flag & R_FLAG)
		return (sort_rev_params(t, flag));
	while (t && t[i].is_last)
	{
		ft_memcpy(&tmp, t + i, sizeof(t_params));
		while (j > 0 &&
				(((flag & T_FLAG) && t[j - 1].time < tmp.time) ||
				(!(flag & T_FLAG) && ft_strcmp(t[j - 1].name, tmp.name) > 0)))
		{
			ft_memcpy(t + j, t + (j - 1), sizeof(t_params));
			j--;
		}
		ft_memcpy(t + j, &tmp, sizeof(t_params));
		i++;
		j = i;
	}
	return (t);
}

static t_files		*sort_rev_files(t_files *t, short flag)
{
	t_files	tmp;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (t[i].is_last)
	{
		ft_memcpy(&tmp, t + i, sizeof(t_files));
		while (j > 0 &&
				(((flag & T_FLAG) && t[j - 1].time > tmp.time) ||
				(!(flag & T_FLAG) && ft_strcmp(t[j - 1].name, tmp.name) < 0)))
		{
			ft_memcpy(t + j, t + (j - 1), sizeof(t_files));
			j--;
		}
		ft_memcpy(t + j, &tmp, sizeof(t_files));
		i++;
		j = i;
	}
	return (t);
}

t_files		*sort_files_st(t_files *t, short flag)
{
	t_files	tmp;
	int		i;
	int		j;

	i = 1;
	j = 1;
	if (!t || t[0].is_last == 0)
		return (t);
	if (flag & R_FLAG)
		return (sort_rev_files(t, flag));
	while (t[i].is_last)
	{
		ft_memcpy(&tmp, t + i, sizeof(t_files));
		while (j > 0 &&
				(((flag & T_FLAG) && t[j - 1].time < tmp.time) ||
				(!(flag & T_FLAG) && ft_strcmp(t[j - 1].name, tmp.name) > 0)))
		{
			ft_memcpy(t + j, t + (j - 1), sizeof(t_files));
			j--;
		}
		ft_memcpy(t + j, &tmp, sizeof(t_files));
		i++;
		j = i;
	}
	return (t);
}
