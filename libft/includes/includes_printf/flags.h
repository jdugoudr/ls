/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:56:28 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/18 11:36:27 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "ft_printf.h"

# define NB_FLAGS	5
# define NO_FLAG	0x0000
# define BL_FLAG	0x0001
# define ZR_FLAG	0x0002
# define MR_FLAG	0x0004
# define PR_FLAG	0x0008
# define MS_FLAG	0x0010
# define LS_FLAG	0x0020
# define L_FLAG		0x0040
# define LL_FLAG	0x0080
# define HH_FLAG	0x0100
# define H_FLAG		0x0200
# define DS_FLAG	0x0400
# define Z_FLAG		0x0800
# define J_FLAG		0x1000
# define LLL_FLAG	0x2000
# define ST_FLAG	0x4000

int		add_flag(const char c, const char *str, t_flags *flags, va_list *ap);
void	list_flag_del(void *del, size_t size);
int		init_tabf(t_fcfl	*tab);
void	init_flags(t_flags *flags);
/*
 **							init flag
*/
int		init_blank(const char c, t_flags *el);
int		init_less(const char c, t_flags *el);
int		init_minisize(const char *str, t_flags *el);
int		init_more(const char c, t_flags *el);
int		init_point(const char c, const char *str, t_flags *el);
int		init_zero(const char c, t_flags *el);
int		init_l(const char c, const char *str, t_flags *el);
int		init_ll(const char c, const char *srt, t_flags *el);
int		init_lll(const char c, t_flags *el);
int		init_hh(const char c, const char *srt, t_flags *el);
int		init_h(const char c, const char *str, t_flags *el);
int		init_ds(const char c, t_flags *el);
int		init_z(const char c, t_flags *el);
int		init_j(const char c, t_flags *el);
int		init_star(const char c, const char *str, t_flags *el, va_list *ap);
/*
 **							manage flags
*/
void	manage_blank(t_convert *t, t_flags *el);
void	manage_minsize(t_convert *t, t_flags *el);
void	manage_more(t_convert *t, t_flags *el);
void	manage_point(t_convert *t, t_flags *el);
void	manage_diese(t_convert *t, t_flags *el);

#endif
