/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:24:08 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/02 19:57:51 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "errno.h"

void	getdata(char *path, t_files *file, struct stat *st)
{
	errno = 0;
	if (st == NULL && (lstat(path, st) == -1))
	{
		if (errno == ENOENT)
			ft_fprintf(STRERR, "ls: %s: %s\n", path, strerror(errno));
		else
			error_ls(file);
	}
	file->time = st->st_mtime;
	if ((st->st_mode & S_IFMT) == S_IFREG)
		file->type = '-';
	else if ((st->st_mode & S_IFMT) == S_IFDIR)
		file->type = 'd';
	else if ((st->st_mode & S_IFMT) == S_IFLNK)
		file->type = 'l';
	else if ((st->st_mode & S_IFMT) == S_IFCHR)
		file->type = 'c';
	else if ((st->st_mode & S_IFMT) == S_IFBLK)
		file->type = 'b';
	else if ((st->st_mode & S_IFMT) == S_IFSOCK)
		file->type = 's';
	else if ((st->st_mode & S_IFMT) == S_IFIFO)
		file->type = 'f';
	ft_printf("getdata : on as deja le type de fichier mais c'est pas fini\n");
}
