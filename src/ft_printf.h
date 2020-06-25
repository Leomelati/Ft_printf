/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:48:27 by lmartins          #+#    #+#             */
/*   Updated: 2020/06/25 09:38:51 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Includes
*/

# include "../Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
** Struct
*/

typedef struct	s_parameters
{
	const char	*format;
	int			i;
	int			signal;
	int			leftJustify;
	int			zero;
	int			width;
	int			precision;
	char		specifier;
	char		*result;
}				t_parameters;

/*
** Defines
*/

# define TRUE 1
# define FALSE 0
# define MISSING -1
# define FLAGS "-+ #0"
# define SPECIFIERS "cspdiuxX%"

/*
** Flag Zero functions
*/

int				flag_zero_hex_lower(unsigned int size, va_list ap);
int				flag_zero_hex(unsigned int size, va_list ap);
int				flag_zero_int(unsigned int size, va_list ap);
int				flag_zero_uns(unsigned int size, va_list ap);
char			*flag_zero(char *format, va_list ap);

/*
** Printf Functions
*/

void			check_flag(t_parameters *info);
void			check_conversion(t_parameters *info);
int				ft_printf(const char *format, ...);

#endif
