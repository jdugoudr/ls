/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:19:02 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/02 21:03:47 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_params	*add_params(t_params **old)
{
	static int	i = 1;
	t_params	*new;

	new = (t_params *)malloc(((i * BUFF_PARAMS) + 1) * sizeof(t_params));
	if (new && i == 1)
		new[0].is_last = 0;
	if (new && i != 1)
		new = ft_memcpy(new, *old, (i * BUFF_PARAMS) * sizeof(t_params));
	free(*old);
	*old = NULL;
	i++;
	return (new);
}

t_files	*add_files(t_files **old)
{
	static int	i = 1;
	t_files		*new;

	new = (t_files *)malloc(((i * BUFF_FILES) + 1) * sizeof(t_files));
	if (new && i != 1)
		new = ft_memcpy(new, *old, (i * BUFF_FILES) * sizeof(t_files));
	free(*old);
	*old = NULL;
	i++;
	return (new);
}

int		split_difi(t_files **file, t_params **dir, char *name, struct stat st)
{
	static int	nb_dir = 0;
	static int	nb_file = 0;

	if ((st.st_mode & S_IFMT) == S_IFDIR)
	{
		if (nb_dir + 1 == BUFF_PARAMS || nb_dir == 0)
			if ((*dir = add_params(dir)) == NULL)
				return (1);
		if (nb_dir != 0)
			(*dir)[nb_dir - 1].is_last = 1;
		(*dir)[nb_dir].name = name;
		(*dir)[nb_dir].time = st.st_mtime;
		(*dir)[nb_dir].is_last = 1;
		(*dir)[nb_dir + 1].is_last = 0;
		nb_dir++;
	}
	else
	{
		if (nb_file + 1 == BUFF_FILES)
			if ((*file = add_files(file)) == NULL)
				return (1);
		getdata(name, (*file) + nb_file, &st);
		if (nb_file != 0)
			(*file)[nb_file - 1].is_last = 1;
		(*file)[nb_file].is_last = 1;
		ft_strcpy((*file)[nb_file].name, name);
		(*file)[nb_file + 1].is_last = 0;
	}
	return (0);
}
