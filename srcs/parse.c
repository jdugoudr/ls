/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:55:26 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/02 20:59:51 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "errno.h"

static t_params	*no_av()
{
	t_params *p;

	if ((p = (t_params *)malloc(1 * sizeof(t_params))) == NULL)
		error_ls(NULL);
	p[0].name = ".";
	p[0].is_last = 0;
	return (p);
}

static void	addflag(short *flag, char c)
{
	if (c == 'l')
		*flag |= L_FLAG;
	else if (c == 'r')
		*flag |= R_FLAG;
	else if (c == 'R')
		*flag |= RR_FLAG;
	else if (c == 'a')
		*flag |= A_FLAG;
	else if (c == 't')
		*flag |= T_FLAG;
}

static int	getflag(short *flag, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0') ||
					!ft_strcmp(av[i], "--"))
			break;
		while (av[i][j] != '\0')
		{
			j++;
			if (!ft_strchr(FLAGS, av[i][j]))
				p_error_ls(av[i][j], NULL);
			addflag(flag, av[i][j]);
		}
		i++;
	}
	if (i < ac && !ft_strcmp(av[i], "--"))
		i++;
	return (i);
}

static void	getfile(t_files **file, t_params **dir, int ac, char **av)
{
	struct stat	st;
	int			i;

	i = 0;
	while (i < ac)
	{
		errno = 0;
		if (lstat(av[i], &st) == -1)
		{
			if (errno == ENOENT)
				ft_fprintf(STRERR, "ls: %s: %s\n", av[i], strerror(errno));
			else
			{
				free(*dir);
				error_ls(*file);
			}
		}
		else if (split_difi(file, dir, av[i], st))
		{
			free(*dir);
			error_ls(*file);
		}
		i++;
	}
}

short	parse(t_files **file, t_params **dir, int ac, char **av)
{
	int		i;
	short	flag;

	flag = 0;
	i = 0;
	if (ac == 0 || (i = getflag(&flag, ac, av)) == ac)
		*dir = no_av();
	else
		getfile(file, dir, ac - i, av + i);
	return (flag);
}
