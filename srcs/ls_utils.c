/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:19:02 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/06 10:20:09 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*n_from_p(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	path[i - 1] = '\0';
	while (path[i] != '/' && i > 0)
		i--;
	if (path[i] == '/')
		i++;
	return (path + i);
}

t_params	*add_params(t_params **old)
{
	static int	i = 0;
	t_params	*new;

	new = (t_params *)malloc((((i + 1) * BUFF_PARAMS) + 1) * sizeof(t_params));
	if (new && i != 0)
		new = ft_memcpy(new, *old, (i * BUFF_PARAMS) * sizeof(t_params));
	free(*old);
	*old = NULL;
	i++;
	return (new);
}

t_files		*add_files(t_files **old, int i)
{
	t_files		*new;

	new = (t_files *)malloc((((i + 1) * BUFF_FILES) + 1) * sizeof(t_files));
	if (new && i != 0)
		new = ft_memcpy(new, *old, (i * BUFF_FILES) * sizeof(t_files));
	free(*old);
	*old = NULL;
	return (new);
}

t_files		*creat_new_tab(void)
{
	t_files	*new;

	new = (t_files *)malloc(((BUFF_FILES) + 1) * sizeof(t_files));
	if (new)
		new[0].is_last = 0;
	return (new);
}

int			split_df(t_files **file, t_params **dir, t_data *dt)
{
	static int	nb_dir = 0;
	static int	nb_file = 0;

	if ((dt->st.st_mode & S_IFMT) == S_IFDIR)
	{
		if ((nb_dir + 1) % BUFF_PARAMS == 0 || nb_dir == 0)
			if ((*dir = add_params(dir)) == NULL)
				return (1);
		(*dir)[nb_dir].name = dt->name;
		(*dir)[nb_dir].time = dt->st.st_mtime;
		(*dir)[nb_dir].is_last = 1;
		(*dir)[nb_dir + 1].is_last = 0;
		nb_dir++;
	}
	else
	{
		if (new_file(file, dt, &nb_file, dt->name))
			return (1);
	}
	return (0);
}
