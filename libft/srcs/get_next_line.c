/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:21:53 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/12/06 09:21:59 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_toline(char *str, char *next)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = NULL;
	if (next)
		len = ft_strlen(str) - ft_strlen(next);
	else
		len = ft_strlen(str);
	if ((tmp = (char*)ft_memalloc((len + 1) * sizeof(char))) == NULL)
	{
		ft_strdel(&str);
		return (NULL);
	}
	ft_strncpy(tmp, str, len);
	return (tmp);
}

static char		*ft_tonext(char *str, char *next)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	tmp = ft_strdup(next + 1);
	ft_strdel(&str);
	return (tmp);
}

static char		*ft_join(char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	ft_strdel(&str);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	tf[FD_MAX];
	int				r;
	char			buff[BUFF_SIZE + 1];
	char			*next;

	if (!line || fd < 0 || fd >= FD_MAX || BUFF_SIZE < 0)
		return (-1);
	if (!tf[fd].str)
		tf[fd].str = (char*)ft_memalloc(sizeof(char));
	while ((next = ft_strchr(tf[fd].str, '\n')) == NULL)
	{
		if ((r = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[r] = '\0';
		if ((tf[fd].str = ft_join(tf[fd].str, buff)) == NULL)
			return (-1);
		else if (r == 0 && tf[fd].str[0] == '\0')
			return (0);
		else if (r == 0)
			break ;
	}
	*line = ft_toline(tf[fd].str, next);
	tf[fd].str = ft_tonext(tf[fd].str, next);
	return (1);
}
