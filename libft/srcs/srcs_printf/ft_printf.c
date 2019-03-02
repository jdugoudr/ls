/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:24:53 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/22 15:19:45 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "init_convert.h"
#include "flags.h"

static int	read_until_flag(const char *str, int *nb_print)
{
	int	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	ft_putnstr(str, i);
	*nb_print += i;
	if (str[i] == '%' && str[i + 1] == '%')
	{
		ft_putchar('%');
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
	ft_putnstr(t->value, t->len);
	free(t->value);
	free(flags.precision);
	free(flags.arg);
	return (i + 1);
}

int			ft_printf(const char *format, ...)
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
		i += read_until_flag(format + i, &nb_cprint);
		if (format[i] == '%')
		{
			i += read_flag(format + (i + 1), &nb_cprint, &tconvert, &ap) + 1;
		}
	}
	va_end(ap);
	return (nb_cprint);
}
