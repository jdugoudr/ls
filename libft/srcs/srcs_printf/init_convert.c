/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:27:17 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/07 09:04:23 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_convert.h"

static void	init_convert_continue(t_convert *t, char c, const char *g_convert)
{
	if (c == g_convert[7])
		t->f = manage_x;
	else if (c == g_convert[8])
		t->f = manage_xx;
	else if (c == g_convert[9])
		t->f = manage_u;
	else if (c == g_convert[10])
		t->f = manage_uu;
	else if (c == g_convert[11])
		t->f = manage_o;
	else if (c == g_convert[12])
		t->f = manage_oo;
	else if (c == g_convert[13])
		t->f = manage_f;
}

void		init_convert_function(t_convert *t, char c, const char *g_convert)
{
	if (c == g_convert[0])
		t->f = manage_d;
	else if (c == g_convert[1])
		t->f = manage_c;
	else if (c == g_convert[2])
		t->f = manage_s;
	else if (c == g_convert[3])
		t->f = manage_i;
	else if (c == g_convert[4])
		t->f = manage_prc;
	else if (c == g_convert[5])
		t->f = manage_dd;
	else if (c == g_convert[6])
		t->f = manage_p;
	else
		init_convert_continue(t, c, g_convert);
}

const char	*init_convert(t_convert *t)
{
	const char	*g_convert;

	g_convert = "dcsi%DpxXuUoOf";
	t->c = 0;
	t->f = NULL;
	t->len = 0;
	return (g_convert);
}
