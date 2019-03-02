/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:46:45 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/02 21:03:46 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printparams(t_params *p)
{
	int	i;

	i = 0;
	if (!p)
		return;
	while (p[i].is_last)
	{
		ft_printf("%s\n", p[i].name);
		i++;
	}
}

void	printfiles(t_files *f)
{
	int	i;

	i = 0;
	if (!f)
		return;
	while (f[i].is_last)
	{
		ft_printf("%s\n", f[i].name);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_files		*fileparams;
	t_params	*dirparams;
	short		flag;

	fileparams = NULL;
	dirparams = NULL;
	if ((fileparams = add_files(&fileparams)) == NULL)
		error_ls(NULL);
	flag = parse(&fileparams, &dirparams, ac - 1, av + 1);
	printfiles(fileparams);
	printparams(dirparams);
	free(fileparams);
	free(dirparams);
	return (0);
}
