/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:04:16 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/11 05:22:23 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adapted_putnbr_hex_lower(size_t nbr, t_parameters *info)
{
	size_t	mod;

	if (nbr > 0)
	{
		mod = nbr % 16;
		if (mod < 10)
			mod += '0';
		else
			mod += ('a' - 10);
		adapted_putnbr_hex_lower(nbr / 16, info);
		write(1, &mod, 1);
		info->result++;
	}
}

void	adapted_putnbr_hex(size_t nbr, t_parameters *info)
{
	size_t mod;

	if (nbr > 0)
	{
		mod = nbr % 16;
		if (mod < 10)
			mod += '0';
		else
			mod += 55;
		adapted_putnbr_hex(nbr / 16, info);
		write(1, &mod, 1);
		info->result++;
	}
}

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
		padding((info->precision - len), '0', info);
	if (info->precision != 0)
	{
		if (ptr == 0)
		{
			write(1, "0", 1);
			info->result++;
		}
		else
			adapted_putnbr_hex_lower(ptr, info);
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
		padding((info->precision - len), '0', info);
	if (info->precision != 0)
	{
		if (ptr == 0)
		{
			write(1, "0", 1);
			info->result++;
		}
		else
			adapted_putnbr_hex(ptr, info);
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
	len = ft_hexlen(ptr);
	spacestoprint = info->width - len;
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	adapted_putstr_fd("0x", 1, info);
	if (!ptr)
		adapted_putstr_fd("0", 1, info);
	else
		adapted_putnbr_hex_lower(ptr, info);
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}
