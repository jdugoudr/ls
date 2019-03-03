/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:12:31 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/03 19:42:39 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_all(t_files *file)
{
	ft_printf("print all of it\n");
}

void		print_ls(t_files *file, short flag)
{
	int	i;

	i = 0;
	while (file[i].is_last)
	{
		if ((file[i].name[0] == '.' && (flag & A_FLAG)) ||
				file[i].name[0] != '.')
		{
			if ((flag & L_FLAG))
				print_all(file);
			else
				ft_printf("%s\n", file[i].name);
		}
		i++;
	}
}
