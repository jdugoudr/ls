/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:37:14 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/03 19:22:47 by jdugoudr         ###   ########.fr       */
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

# define FLAGS			"lrRat"
# define L_FLAG			0x01
# define R_FLAG			0x02
# define A_FLAG			0x04
# define T_FLAG			0x08
# define RR_FLAG		0x10

# define BUFF_PARAMS	10
# define BUFF_FILES		250

typedef struct	s_files
{
	char		name[256];
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

void			get_data(t_files *file, struct stat st);
int				new_file(t_files **file, char *name, struct stat st,
		int nb_file);
int				get_stat(t_files **file, char *path, char *name, int nb_file);
int				read_dir(t_files *file, char *path, short flag);
short			parse(t_files **file, t_params **dir, int ac, char **av);

/*
 ** utils
*/
t_files			*creat_new_tab(void);
t_params		*add_params(t_params **old);
t_files			*add_files(t_files **old, int i);
int				split_df(t_files **file, t_params **dir,
				char *name, struct stat st);
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
void			print_ls(t_files *file, short flag);
#endif
