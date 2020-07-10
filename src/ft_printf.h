/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:48:27 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 08:46:58 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Includes
*/

# include "../Libft/libft.h"
# include <stdarg.h>

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
** Printf Functions
*/

void	start_infos(t_parameters *info);
void	mount_result(t_parameters *info, va_list ap);
int		ft_printf(const char *format, ...);

/*
** Parameters Functions
*/

void	check_flag(t_parameters *info);
void	check_width(t_parameters *info, va_list ap);
void	check_precision(t_parameters *info, va_list ap);

/*
** Hexadecimal Functions
*/

void	print_x_specifier(t_parameters *info, va_list ap);
void	print_upper_x_specifier(t_parameters *info, va_list ap);
void	print_p_specifier(t_parameters *info, va_list ap);

/*
** Numbers Functions
*/

void	print_d_specifier(t_parameters *info, va_list ap);
void	print_u_specifier(t_parameters *info, va_list ap);

/*
** Strings Functions
*/

void	print_c_specifier(t_parameters *info, va_list ap);
void	print_s_specifier(t_parameters *info, va_list ap);
void	print_percentage_specifier(t_parameters *info);

/*
** Utils Functions
*/

void	padding(int spacestoprint, char chartoprint);

#endif
