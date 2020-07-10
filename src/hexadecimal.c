/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:04:16 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 10:21:04 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int				len;
	int				spacestoprint;
	char			chartoprint;

	ptr = (size_t)va_arg(ap, unsigned int);
	chartoprint = determine_char(info);
	len = ft_hexlen(ptr) - ((ptr > 0) ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	spacestoprint = determine_spaces(len, info);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0');
	if (info->precision != 0)
	{
		if (ptr == 0)
			write(1, "0", 1);
		else
			ft_putnbr_hex_lower(ptr);
	}
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}

void	print_upper_x_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int				len;
	int				spacestoprint;
	char			chartoprint;

	ptr = (size_t)va_arg(ap, unsigned int);
	chartoprint = determine_char(info);
	len = ft_hexlen(ptr) - ((ptr > 0) ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	spacestoprint = determine_spaces(len, info);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0');
	if (info->precision != 0)
	{
		if (ptr == 0)
			write(1, "0", 1);
		else
			ft_putnbr_hex(ptr);
	}
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}

void	print_p_specifier(t_parameters *info, va_list ap)
{
	size_t	ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = (size_t)va_arg(ap, void *);
	chartoprint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_hexlen(ptr) + 1;
	else
		len = info->precision;
	spacestoprint = (len >= info->width) ? 0 : (info->width - len);
	(!ptr) ? spacestoprint-- : 0;
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	ft_putstr_fd("0x", 1);
	(!ptr) ? ft_putstr_fd("0", 1) : ft_putnbr_hex_lower(ptr);
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}
