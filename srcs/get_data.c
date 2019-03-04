/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:24:08 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/04 13:23:41 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

static void	get_data(t_files *file, struct stat st)
{
	file->time = st.st_mtime;
	file->uid = st.st_uid;
	file->gid = st.st_gid;
	file->nlink = st.st_nlink;
	file->len_link = ft_nblen(file->nlink);
	file->size = st.st_size;
	file->len_size = ft_nblen(file->size);
	if ((st.st_mode & S_IFMT) == S_IFREG)
		file->type = '-';
	else if ((st.st_mode & S_IFMT) == S_IFDIR)
		file->type = 'd';
	else if ((st.st_mode & S_IFMT) == S_IFLNK)
		file->type = 'l';
	else if ((st.st_mode & S_IFMT) == S_IFCHR)
		file->type = 'c';
	else if ((st.st_mode & S_IFMT) == S_IFBLK)
		file->type = 'b';
	else if ((st.st_mode & S_IFMT) == S_IFSOCK)
		file->type = 's';
	else if ((st.st_mode & S_IFMT) == S_IFIFO)
		file->type = 'f';
	get_perm(file, st);
	get_name_user(file);
}

int			new_file(t_files **file, char *name, struct stat st, int nb_file)
{
	if ((nb_file + 1) % BUFF_FILES == 0)
		if ((*file = add_files(file, (nb_file + 1) / BUFF_FILES)) == NULL)
			return (1);
	(*file)[nb_file].is_last = 1;
	ft_strcpy((*file)[nb_file].name, name);
	(*file)[nb_file + 1].is_last = 0;
	get_data((*file) + nb_file, st);
	return (0);
}

int			get_stat(t_files **file, char *path, char *name, int nb_file)
{
	struct stat		stat;
	char			*tmp;

	if (!(tmp = ft_strjoin(path, name)))
		return (1);
	errno = 0;
	if (lstat(tmp, &stat) == -1)
	{
		if (errno == ENOENT)
			ft_fprintf(STRERR, "ls: %s: %s\n", name, strerror(errno));
		else
		{
			free(tmp);
			return (1);
		}
	}
	if (new_file(file, name, stat, nb_file))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
