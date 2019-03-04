/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:12:31 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/04 14:00:45 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*norm_date(time_t t)
{
	char	*date;

	date = ctime(&t);
	if (!date)
		return (NULL);
	date[10] = '\0';
	ft_printf("%s ", date + 3);
	if (t - time(NULL) >= SIXMONTHS || time(NULL) - t >= SIXMONTHS)
	{
		date[24] = '\0';
		return (date + 19);
	}
	date[16] = '\0';
	return (date + 11);
}

static void	print_all(t_files f, size_t *tab_max)
{
	ft_printf("%c%s%s%s%c", f.type, f.p_use, f.p_gpe, f.p_oth, ' ');
	ft_printf(" %*hu", (int)tab_max[0], f.nlink);
	if (f.user)
		ft_printf(" %-*s", (int)tab_max[1], f.user);
	else
		ft_printf(" %-*d", (int)tab_max[1], f.uid);
	if (f.gpe)
		ft_printf("  %-*s", (int)tab_max[2], f.gpe);
	else
		ft_printf("  %-*d", (int)tab_max[2], f.gpe);
	ft_printf("  %*d", (int)tab_max[3], f.size);
	ft_printf("%s", norm_date(f.time));
	ft_printf(" %s\n", f.name);
}

static void	take_bigger(size_t *tab_max, t_files *file)
{
	int	i;

	i = 0;
	tab_max[0] = 0;
	tab_max[1] = 0;
	tab_max[2] = 0;
	tab_max[3] = 0;
	while (file[i].is_last)
	{
		if (file[i].len_link > tab_max[0])
			tab_max[0] = file[i].len_link;
		if (file[i].len_user > tab_max[1])
			tab_max[1] = file[i].len_user;
		if (file[i].len_gpe > tab_max[2])
			tab_max[2] = file[i].len_gpe;
		if (file[i].len_size > tab_max[3])
			tab_max[3] = file[i].len_size;
		i++;
	}
}

void		print_ls(t_files *file, short flag)
{
	int		i;
	size_t	tab_max[4];

	i = 0;
	take_bigger(tab_max, file);
	while (file[i].is_last)
	{
		if ((file[i].name[0] == '.' && (flag & A_FLAG)) ||
				file[i].name[0] != '.')
		{
			if ((flag & L_FLAG))
				print_all(file[i], tab_max);
			else
				ft_printf("%s\n", file[i].name);
		}
		i++;
	}
}
