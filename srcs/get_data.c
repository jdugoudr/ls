/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:24:08 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/05 19:10:43 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

static void	get_data(t_files *file, struct stat st)
{
	file->uid = st.st_uid;
	file->gid = st.st_gid;
	file->nlink = st.st_nlink;
	file->len_link = ft_nblen(file->nlink);
	if (file->type != 'c' && file->type != 'b')
	{
		file->size = st.st_size;
		file->len_size = ft_nblen(file->size);
	}
	else
	{
		file->major = major(st.st_rdev);
		file->minor = minor(st.st_rdev);
	}
	file->blocks = st.st_blocks;
	get_perm(file, st);
	get_name_user(file);
}

static void	get_type(t_files *file, struct stat st, char *path)
{
	char	*tmp;
	if ((st.st_mode & S_IFMT) == S_IFREG)
		file->type = '-';
	else if ((st.st_mode & S_IFMT) == S_IFDIR)
		file->type = 'd';
	else if ((st.st_mode & S_IFMT) == S_IFLNK)
	{
		tmp = ft_strnew(256);
		readlink(path, tmp, 256);
		ft_strcpy(file->name_link, tmp);
		free(tmp);
		file->type = 'l';
	}
	else if ((st.st_mode & S_IFMT) == S_IFCHR)
		file->type = 'c';
	else if ((st.st_mode & S_IFMT) == S_IFBLK)
		file->type = 'b';
	else if ((st.st_mode & S_IFMT) == S_IFSOCK)
		file->type = 's';
	else if ((st.st_mode & S_IFMT) == S_IFIFO)
		file->type = 'p';
}

int			new_file(t_files **file, t_data *dt, int *nb_file, char *path)
{
	if ((*nb_file + 1) % BUFF_FILES == 0)
		if ((*file = add_files(file, (*nb_file + 1) / BUFF_FILES)) == NULL)
			return (1);
	(*file)[*nb_file].is_last = 1;
	ft_strcpy((*file)[*nb_file].name, dt->name);
	(*file)[*nb_file + 1].is_last = 0;
	get_type((*file) + *nb_file, dt->st, path);
	if ((dt->flag & T_FLAG) || (dt->flag & L_FLAG))
		((*file)[*nb_file]).time = dt->st.st_mtime;
	if ((dt->flag & L_FLAG))
		get_data((*file) + *nb_file, dt->st);
	if ((dt->flag & I_FLAG))
		(*file)[*nb_file].inode = dt->st.st_ino;
	*nb_file += 1;
	return (0);
}

int			get_stat(t_files **file, char *path, t_data *dt, int *nb_file)
{
	char	*tmp;
	int		r;

	if (!(tmp = ft_strjoin(path, dt->name)))
		return (1);
	errno = 0;
	if ((r = lstat(tmp, &(dt->st))) == -1)
	{
		if (errno != ENOENT && errno != EACCES && errno != EBADF)
		{
			free(tmp);
			return (1);
		}
	}
	else if (dt->name[0] == '.' && (dt->flag & A_FLAG) == 0)
		;
	else if (new_file(file, dt, nb_file, tmp))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (r);
}
