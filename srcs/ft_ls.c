/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:46:45 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/05 19:41:52 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

static int	read_params(t_params *p, t_files *file, short flag)
{
	int		i;
	int		r;
	char	*tmp;

	r = 0;
	i = 0;
	if (!p)
		return (1);
	if (file[0].is_last)
		ft_printf("\n");
	while (p[i].is_last)
	{
		if (i == 0 && (p[1].is_last || file[0].is_last))
			ft_printf("%s:\n", p[i].name);
		else if (p[1].is_last)
			ft_printf("\n%s:\n", p[i].name);
		tmp = ft_strjoin(p[i].name, "/");
		if ((r += read_dir(creat_new_tab(), tmp, flag)) == 1)
			error_ls(file);
		i++;
	}
	return (r);
}

static void	print_files(t_files *f, short flag)
{
	if (!f)
		return ;
	flag |= A_FLAG;
	print_ls(f, flag, NO_TOTAL);
}

int			main(int ac, char **av)
{
	t_files		*fileparams;
	t_params	*dirparams;
	short		flag;
	int			r;

	fileparams = NULL;
	dirparams = NULL;
	if ((fileparams = creat_new_tab()) == NULL)
		error_ls(NULL);
	flag = parse(&fileparams, &dirparams, ac - 1, av + 1);
	if (!fileparams || fileparams[0].is_last)
		fileparams = sort_files_st(fileparams, flag);
	dirparams = sort_params_st(dirparams, flag);
	print_files(fileparams, flag);
	r = read_params(dirparams, fileparams, flag);
	free(fileparams);
	free(dirparams);
	if (r != 0)
		return (1);
	return (0);
}
