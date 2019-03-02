/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:50:10 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/12/21 18:17:15 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "ft_printf.h"

# define ERR_NO_CONV		"Error, no valid conversion."
# define ERR_ADD_LIST		"Error, not possible to create a new list."
# define ERR_STR			"Error, not possible to create a new string."
# define ERR_FLAG			"Error, no valid flag or not possible to use it."
# define ERR_NOT_AVAIBLE	"Error, flag not avaible with this conversion."

void	error(char *flag, char *to_free);

#endif
