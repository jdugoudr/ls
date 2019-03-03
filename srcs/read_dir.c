/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:31:06 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/03 20:13:56 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <errno.h>

static void	print_de_test(t_files *t)
{
	int	i;

	i = 0;
	while (t[i].is_last)
	{
		ft_printf("coucou %s c'est -%c-\n", t[i].name, t[i].type);
		i++;
	}
}

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

static int	for_recursive(t_files *file, char *path, short flag)
{
	int		i;
	size_t	len_path;
	size_t	len_name;
	char	*new_path;

	i = 0;
	while (file[i].is_last)
	{
		if (file[i].type == 'd' && ft_strcmp(file[i].name, ".") &&
				ft_strcmp(file[i].name, ".."))
		{
			len_path = ft_strlen(path);
			len_name = ft_strlen(file[i].name);
			if (!(new_path = malloc((len_path + len_name + 2) * sizeof(char))))
				return (1);
			new_path = ft_strcpy(new_path, path);
			new_path = ft_strcat(new_path, file[i].name);
			ft_printf("\n%s:\n", new_path);
			new_path = ft_strcat(new_path, "/");
			if (read_dir(creat_new_tab(), new_path, flag) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int			read_dir(t_files *file, char *path, short flag)
{
	DIR				*dir;
	struct dirent	*cont_dir;
	int				i;
	char			*new_path;

	if (!file)
		return (1);
	if ((i = open_dir(path, &dir)) != 0)
	{
		free(file);
		file = NULL;
		free(path);
		return (i);
	}
	while ((cont_dir = readdir(dir)) != NULL)
		if (get_stat(&file, path, cont_dir->d_name, i++))
			error_ls(file);
	file = sort_files_st(file, flag);
	print_ls(file, flag);
	if (flag & RR_FLAG)
		i = for_recursive(file, path, flag);
	free(path);
	free(file);
	closedir(dir);
	return (i);
}
