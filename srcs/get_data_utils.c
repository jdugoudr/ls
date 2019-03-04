/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:29:36 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/04 18:22:57 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_name_user(t_files *file)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(file->uid);
	file->user = pwd->pw_name;
	grp = getgrgid(file->gid);
	file->gpe = grp->gr_name;
	if (!file->user)
		file->len_user = ft_nblen(file->uid);
	else
		file->len_user = ft_strlen(file->user);
	if (!file->gpe)
		file->len_gpe = ft_nblen(file->gid);
	else
		file->len_gpe = ft_strlen(file->gpe);
}

static void	still_exec(t_files *file, struct stat st)
{
	if ((st.st_mode & S_IXOTH) && (st.st_mode & S_ISVTX))
		file->p_oth[2] = 't';
	else if ((st.st_mode & S_IXOTH) == 0 && (st.st_mode & S_ISVTX))
		file->p_oth[2] = 'T';
	else if ((st.st_mode & S_IXOTH))
		file->p_oth[2] = 'x';
	else
		file->p_oth[2] = '-';
	file->p_use[3] = '\0';
	file->p_gpe[3] = '\0';
	file->p_oth[3] = '\0';
}

void	get_exec(t_files *file, struct stat st)
{
	if ((st.st_mode & S_IXUSR) && (st.st_mode & S_ISUID) == 0)
		file->p_use[2] = 'x';
	else if ((st.st_mode & S_IXUSR) && (st.st_mode & S_ISUID))
		file->p_use[2] = 's';
	else if ((st.st_mode & S_IXUSR) == 0 && (st.st_mode & S_ISUID))
		file->p_use[2] = 'S';
	else
		file->p_use[2] = '-';
	if ((st.st_mode & S_IXGRP) && (st.st_mode & S_ISGID) == 0)
		file->p_gpe[2] = 'x';
	else if ((st.st_mode & S_IXGRP) && (st.st_mode & S_ISGID))
		file->p_gpe[2] = 's';
	else if ((st.st_mode & S_IXGRP) == 0 && (st.st_mode & S_ISGID))
		file->p_gpe[2] = 'S';
	else
		file->p_gpe[2] = '-';
	still_exec(file, st);
}

void	get_perm(t_files *file, struct stat st)
{
	if ((st.st_mode & S_IRUSR))
		file->p_use[0] = 'r';
	else
		file->p_use[0] = '-';
	if ((st.st_mode & S_IWUSR))
		file->p_use[1] = 'w';
	else
		file->p_use[1] = '-';
	if ((st.st_mode & S_IRGRP))
		file->p_gpe[0] = 'r';
	else
		file->p_gpe[0] = '-';
	if ((st.st_mode & S_IWGRP))
		file->p_gpe[1] = 'w';
	else
		file->p_gpe[1] = '-';
	if ((st.st_mode & S_IROTH))
		file->p_oth[0] = 'r';
	else
		file->p_oth[0] = '-';
	if ((st.st_mode & S_IWOTH))
		file->p_oth[1] = 'w';
	else
		file->p_oth[1] = '-';
	get_exec(file, st);
}
