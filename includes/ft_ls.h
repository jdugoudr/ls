/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:37:14 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/02 20:22:46 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

# define STRERR			2
# define USAGE			"usage: ls [-lartR] [file ...]"

# define FLAGS			"lrRat"
# define L_FLAG			0x01
# define R_FLAG			0x02
# define A_FLAG			0x04
# define T_FLAG			0x08
# define RR_FLAG		0x10

# define BUFF_PARAMS	10
# define BUFF_FILES		50

typedef struct	s_files
{
	char		name[257];
	time_t		time;
	char		type;
	nlink_t		nlink;
	char		*user;
	char		*gpe;
	uid_t		uid;
	gid_t		gid;
	int			is_last;
}				t_files;

typedef struct	s_params
{
	char		*name;
	time_t		time;
	int			is_last;
}				t_params;

//int				ft_scandir(char *path, t_datafile *dfile);
//int				print(t_datafile dfile, char *path);
//int				sort(char *path, t_datafile *dfile);
//int				sort_first_param(char **tab, short flag);
void			getdata(char *path, t_files *file, struct stat *st);
short			parse(t_files **file, t_params **dir, int ac, char **av);
//int				addtabstr(char ***tab, char *str);
//char			*get_name(char *path);
//time_t			*gettime(char **tabstr, char *path, size_t len, int is_first);
//char			*add_path(char *path, char *name);
//int				extract_dir(char *path, t_datafile *dfile);
//void			no_param(char ***dir);

/*
 ** utils
 */
t_params		*add_params(t_params **old);
t_files			*add_files(t_files **old);
int				split_difi(t_files **file, t_params **dir,
				char *name, struct stat st);
/*
 ** error
 */
void			error_ls(t_files *file);
void			p_error_ls(char c, t_files *file);
////////////////////// a suprrimer avant push !!! juste pour debug !!!
//void	printtab(char **tab);
void	printparams(t_params *p);
void	printfiles(t_files *f);

#endif
