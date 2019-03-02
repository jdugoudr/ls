/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utility.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:10:32 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/02/04 18:47:02 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_UTILITY_H
# define FLAG_UTILITY_H

# include "ft_printf.h"

void	filled_str(char *str, char c, int nb, char *src);
void	filled_frback(char *str, char c, int nb);
char	*pt_for_f(t_convert *t, t_flags *el, char *norm, size_t *nb_digit);
int		nb_print_for_point(t_convert *t, size_t nb_digit);
int		need_appro(char *s);

#endif
