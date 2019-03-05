/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:07:04 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/05 15:08:19 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

off_t	take_bigger(size_t *tab_max, t_files *file)
{
	int		i;
	off_t	total;

	i = 0;
	total = 0;
	while (file[i].is_last)
	{
		total += file[i].blocks;
		if (file[i].len_link > tab_max[0])
			tab_max[0] = file[i].len_link;
		if (file[i].len_user > tab_max[1])
			tab_max[1] = file[i].len_user;
		if (file[i].len_gpe > tab_max[2])
			tab_max[2] = file[i].len_gpe;
		if (file[i].type != 'c' && file[i].type != 'b' &&
				file[i].len_size > tab_max[3])
			tab_max[3] = file[i].len_size;
		else if ((file[i].type == 'c' || file[i].type == 'b') && 8 > tab_max[3])
			tab_max[3] = 8;
		i++;
	}
	return (total);
}

ino_t	max_inode(t_files *file)
{
	int		i;
	ino_t	max;

	i = 0;
	max = 0;
	while (file[i].is_last)
	{
		if (file[i].inode > max)
			max = ft_nblen(file[i].inode);
		i++;
	}
	return (max);
}
