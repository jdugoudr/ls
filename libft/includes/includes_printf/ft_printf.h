/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:10:17 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/22 15:17:32 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include "error.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_flags
{
	unsigned short	fc;
	char			*arg;
	char			*precision;
	short			do_star;
	void			*tabf;
}					t_flags;

typedef struct		s_convert
{
	char			c;
	char			*value;
	size_t			len;
	int				(*f)(struct s_convert*, t_flags *flags, va_list *ap);
}					t_convert;

typedef	void		(*t_fcfl)(t_convert *, t_flags *);

int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);

int					run_flags(t_convert *t, t_flags *flags, t_fcfl tabf[]);
void				norm_hex(t_convert *t);
void				norm_oct(t_convert *t);

int					manage_d(t_convert *d, t_flags *flags, va_list *ap);
int					manage_i(t_convert *d, t_flags *flags, va_list *ap);
int					manage_c(t_convert *d, t_flags *flags, va_list *ap);
int					manage_s(t_convert *d, t_flags *flags, va_list *ap);
int					manage_prc(t_convert *d, t_flags *flags, va_list *ap);
int					manage_dd(t_convert *t, t_flags *flags, va_list *ap);
int					manage_p(t_convert *t, t_flags *flags, va_list *ap);
int					manage_x(t_convert *t, t_flags *flags, va_list *ap);
int					manage_xx(t_convert *t, t_flags *flags, va_list *ap);
int					manage_u(t_convert *t, t_flags *flags, va_list *ap);
int					manage_uu(t_convert *t, t_flags *flags, va_list *ap);
int					manage_o(t_convert *t, t_flags *flags, va_list *ap);
int					manage_oo(t_convert *t, t_flags *flags, va_list *ap);
int					manage_f(t_convert *t, t_flags *flags, va_list *ap);

#endif
