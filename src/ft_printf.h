/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:48:27 by lmartins          #+#    #+#             */
/*   Updated: 2020/05/28 14:43:43 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		flag_zero_hex_lower(unsigned int size, va_list ap);
int		flag_zero_hex(unsigned int size, va_list ap);
int		flag_zero_int(unsigned int size, va_list ap);
int		flag_zero_uns(unsigned int size, va_list ap);
char	*flag_zero(char *format, va_list ap);
char	*check_flag(char *format, va_list ap);
void	check_conversion(char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif
