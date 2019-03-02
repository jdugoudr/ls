/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_convert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:25:05 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/01/17 16:33:13 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_CONVERT_H
# define INIT_CONVERT_H

# include "ft_printf.h"

const char	*init_convert(t_convert *t);
void		init_convert_function(t_convert *t, char c, const char *g_convert);

#endif
