/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:23:51 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/12/06 12:45:52 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"

# define FD_MAX		4864
# define BUFF_SIZE	50

typedef struct		s_file
{
	char			*str;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
