/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:16:17 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/22 15:28:01 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "init_convert.h"
#include "flags.h"

static int	read_until_flag(int fd, const char *str, int *nb_print)
{
	int	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	ft_putnstr_fd(str, i, fd);
	*nb_print += i;
	if (str[i] == '%' && str[i + 1] == '%')
	{
		ft_putchar_fd('%', fd);
		*nb_print += 1;
		i += 2;
	}
	return (i);
}

static int	read_flag(const char *str, int *nb_print, t_convert *t, va_list *ap)
{
	int			i;
	t_flags		flags;
	const char	*g_convert;

	t->value = NULL;
	init_flags(&flags);
	g_convert = init_convert(t);
	i = 0;
	while (str[i] != '\0' && ft_strchr(g_convert, str[i]) == NULL)
		i += add_flag(str[i], str + i, &flags, ap);
	if (str[i] == '\0')
		error(ERR_NO_CONV, NULL);
	t->c = *(str + i);
	init_convert_function(t, t->c, g_convert);
	*nb_print += t->f(t, &flags, ap);
	free(flags.precision);
	free(flags.arg);
	return (i + 1);
}

int			ft_fprintf(int fd, const char *format, ...)
{
	t_convert	tconvert;
	va_list		ap;
	int			i;
	int			nb_cprint;

	i = 0;
	nb_cprint = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		i += read_until_flag(fd, format + i, &nb_cprint);
		if (format[i] == '%')
		{
			i += read_flag(format + (i + 1), &nb_cprint, &tconvert, &ap) + 1;
			ft_putnstr_fd(tconvert.value, tconvert.len, fd);
			free(tconvert.value);
		}
	}
	va_end(ap);
	return (nb_cprint);
}
