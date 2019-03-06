/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:46:18 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/06 10:31:45 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_ls(t_files *file)
{
	perror("ls");
	free(file);
	exit(1);
}

void	p_error_ls(char c, t_files *file)
{
	ft_fprintf(STRERR, "ls: illegal option -- %c\n", c);
	ft_fprintf(STRERR, "%s\n", USAGE);
	free(file);
	exit(1);
}
