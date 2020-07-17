/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:48:27 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 08:43:30 by lmartins         ###   ########.fr       */
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
	int			leftjustify;
	int			zero;
	int			width;
	int			precision;
	char		specifier;
	int			result;
}				t_parameters;

/*
** Defines
*/

# define TRUE 1
# define FALSE 0
# define MISSING -1
# define FLAGS "- 0"
# define SPECIFIERS "cspdiuxX%"

/*
** Printf Functions
*/

void			prepare_infos(t_parameters *info, va_list ap);
void			mount_result(t_parameters *info, va_list ap);
int				ft_printf(const char *format, ...);

/*
** Parameters Functions
*/

void			check_flag(t_parameters *info);
void			check_width(t_parameters *info, va_list ap);
void			check_precision(t_parameters *info, va_list ap);

/*
** Hexadecimal Functions
*/

void			print_x_specifier(t_parameters *info, va_list ap);
void			print_upper_x_specifier(t_parameters *info, va_list ap);
void			print_p_specifier(t_parameters *info, va_list ap);

/*
** Numbers Functions
*/

void			print_int(int len, t_parameters *info, char *ptr);
void			print_d_specifier(t_parameters *info, va_list ap);
void			print_u_specifier(t_parameters *info, va_list ap);

/*
** Strings Functions
*/

void			adapted_putstr_fd(char *s, int fd, t_parameters *info);
void			adapted_putchar_fd(char c, int fd, t_parameters *info);
void			print_c_specifier(t_parameters *info, va_list ap);
void			print_s_specifier(t_parameters *info, va_list ap);
void			print_percentage_specifier(t_parameters *info);

/*
** Utils Functions
*/

void			justify_padding(int spaces, char c, t_parameters *info,
					int option);
void			padding(int spaces, char c, t_parameters *info);
char			determine_char(t_parameters *info);
void			start_infos(t_parameters *info);
void			restart_infos(t_parameters *info);

#endif
