/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:46:45 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/03 18:44:26 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

static void	read_params(t_params *p, t_files *file, short flag)
{
	int	i;
	int	r;

	i = 0;
	if (!p)
		return ;
	while (p[i].is_last)
	{
		ft_printf("%s\n", p[i].name);
		if (read_dir(creat_new_tab(), ft_strjoin(p[i].name, "/"), flag) == 1)
			error_ls(file);
		i++;
	}
}

static void	printfiles(t_files *f)
{
	int	i;

	i = 0;
	if (!f)
		return ;
	while (f[i].is_last)
	{
		ft_printf("%s\n", f[i].name);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_files		*fileparams;
	t_params	*dirparams;
	short		flag;

	fileparams = NULL;
	dirparams = NULL;
	if ((fileparams = creat_new_tab()) == NULL)
		error_ls(NULL);
	flag = parse(&fileparams, &dirparams, ac - 1, av + 1);
	fileparams = sort_files_st(fileparams, flag);
	dirparams = sort_params_st(dirparams, flag);
	printfiles(fileparams);
	read_params(dirparams, fileparams, flag);
	free(fileparams);
	free(dirparams);
	return (0);
}
