/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:55:26 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/05 13:50:12 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "errno.h"

static t_params	*no_av(void)
{
	t_params *p;

	if ((p = (t_params *)malloc(2 * sizeof(t_params))) == NULL)
		error_ls(NULL);
	p[0].name = ".";
	p[0].is_last = 1;
	p[1].is_last = 0;
	return (p);
}

static void		addflag(short *flag, char c)
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

static int		get_flag(short *flag, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0') ||
					!ft_strcmp(av[i], "--"))
			break ;
		while (av[i][j] != '\0')
		{
			j++;
			if (!ft_strchr(FLAGS, av[i][j]))
				p_error_ls(av[i][j], NULL);
			addflag(flag, av[i][j]);
		}
		j = 0;
		i++;
	}
	if (i < ac && !ft_strcmp(av[i], "--"))
		i++;
	return (i);
}

static int		get_file(char *name, struct stat *st, short flag, t_data *dt)
{
	int	r;

	r = 0;
	errno = 0;
	if (flag & L_FLAG)
		r = lstat(name, st);
	else
		r = stat(name, st);
	if (r == -1)
	{
		if (errno == ENOENT)
			ft_fprintf(STRERR, "ls: %s: %s\n", name, strerror(errno));
		else
			return (1);
		return (-1);
	}
	dt->name = name;
	dt->st = *st;
	dt->flag = flag;
	return (0);
}

short			parse(t_files **file, t_params **dir, int ac, char **av)
{
	int			i;
	int			r;
	short		flag;
	struct stat	st;
	t_data		dt;

	flag = 0;
	i = 0;
	if (ac == 0 || (i = get_flag(&flag, ac, av)) == ac)
		*dir = no_av();
	else
		while (i < ac)
		{
			if ((r = get_file(av[i], &st, flag, &dt)) == 0)
				r = split_df(file, dir, &dt);
			if (r == 1)
			{
				free(*dir);
				error_ls(*file);
			}
			i++;
		}
	return (flag);
}
