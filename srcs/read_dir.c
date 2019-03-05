/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:31:06 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/05 19:41:24 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <errno.h>

static int	open_dir(char *path, DIR **dir)
{
	if (!path)
		return (1);
	errno = 0;
	*dir = opendir(path);
	if (*dir == NULL)
	{
		if (errno == EACCES || errno == EBADF || errno == ENOTDIR)
		{
			ft_fprintf(STRERR, "ls: %s: %s\n", n_from_p(path), strerror(errno));
			return (-1);
		}
		else
			return (1);
	}
	return (0);
}

static int	for_recursive(t_files *file, char *path, short flag, int r)
{
	int		i;
	size_t	len_path;
	char	*new_path;

	i = 0;
	while (file[i].is_last)
	{
		if (file[i].type == 'd' && ft_strcmp(file[i].name, ".") &&
				ft_strcmp(file[i].name, ".."))
		{
			len_path = ft_strlen(path);
			len_path += ft_strlen(file[i].name);
			if (!(new_path = malloc((len_path + 2) * sizeof(char))))
				return (1);
			new_path = ft_strcpy(new_path, path);
			new_path = ft_strcat(new_path, file[i].name);
			ft_printf("\n%s:\n", new_path);
			new_path = ft_strcat(new_path, "/");
			if ((r += read_dir(creat_new_tab(), new_path, flag)) == 1)
				return (1);
		}
		i++;
	}
	return (r);
}

static int	read_utils(t_files **file, char *path, short flag, DIR *dir)
{
	t_data			dt;
	int				nb_file;
	int				r;
	struct dirent	*cont_dir;

	nb_file = 0;
	while ((cont_dir = readdir(dir)) != NULL)
	{
		dt.name = cont_dir->d_name;
		dt.flag = flag;
		if ((r = get_stat(file, path, &dt, &nb_file)) == 1)
			error_ls(*file);
		else if (r == -1)
			break ;
	}
	return (r);
}

int			read_dir(t_files *file, char *path, short flag)
{
	DIR				*dir;
	int				i;

	if (!file)
		return (1);
	if ((i = open_dir(path, &dir)) != 0)
	{
		free(file);
		file = NULL;
		free(path);
		return (i);
	}
	if ((i = read_utils(&file, path, flag, dir)) == 0)
	{
		if (file || file[0].is_last)
			file = sort_files_st(file, flag);
		print_ls(file, flag, DO_TOTAL);
		if (flag & RR_FLAG)
			i += for_recursive(file, path, flag, 0);
	}
	free(path);
	free(file);
	closedir(dir);
	return (i);
}
