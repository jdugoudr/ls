/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:37:14 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/06 10:47:50 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>

# define STRERR			2
# define USAGE			"usage: ls [-lartR] [file ...]"

# define FLAGS			"lrRati"
# define L_FLAG			0x01
# define R_FLAG			0x02
# define A_FLAG			0x04
# define T_FLAG			0x08
# define RR_FLAG		0x10
# define I_FLAG			0x20

# define BUFF_PARAMS	10
# define BUFF_FILES		350

# define SIXMONTHS		((365 / 2) * 86400)
# define DO_TOTAL		1
# define NO_TOTAL		0

typedef struct	s_files
{
	char		name[256];
	char		name_link[256];
	time_t		time;
	char		type;
	nlink_t		nlink;
	ino_t		inode;
	size_t		len_link;
	off_t		size;
	size_t		len_size;
	char		p_use[4];
	char		p_gpe[4];
	char		p_oth[4];
	char		*user;
	size_t		len_user;
	char		*gpe;
	size_t		len_gpe;
	uid_t		uid;
	gid_t		gid;
	blkcnt_t	blocks;
	int			major;
	int			minor;
	char		attr;
	int			is_last;
}				t_files;

typedef struct	s_params
{
	char		*name;
	time_t		time;
	int			is_last;
}				t_params;

typedef struct	s_data
{
	char		*name;
	struct stat	st;
	short		flag;
}				t_data;

int				new_file(t_files **file, t_data *dt, int *nb_file, char *path);
int				get_stat(t_files **file, char *path, t_data *dt, int *nb_file);
int				read_dir(t_files *file, char *path, short flag);
short			parse(t_files **file, t_params **dir, int ac, char **av);

/*
 ** utils
*/
t_files			*creat_new_tab(void);
t_params		*add_params(t_params **old);
t_files			*add_files(t_files **old, int i);
int				split_df(t_files **file, t_params **dir, t_data *dt);
char			*n_from_p(char *path);

/*
 ** error
*/
void			error_ls(t_files *file);
void			p_error_ls(char c, t_files *file);

/*
 ** sort
*/
t_params		*sort_params_st(t_params *t, short flag);
t_files			*sort_files_st(t_files *t, short flag);

/*
 ** print
*/
void			print_ls(t_files *file, short flag, int do_total);
off_t			take_bigger(size_t *tab_max, t_files *file);

/*
 ** print_utils
*/
int				max_inode(t_files *file);
off_t			take_bigger(size_t *tab_max, t_files *file);

/*
 ** get_data_utils
*/
void			get_name_user(t_files *file);
void			get_exec(t_files *file, struct stat st);
void			get_perm(t_files *file, struct stat st);

#endif
