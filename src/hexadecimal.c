/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:04:16 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 08:05:36 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int				i;
	int				len;
	int				spacestoprint;
	char			chartoprint;

	ptr = (size_t)va_arg(ap, unsigned int);
	if ((info->zero == TRUE) && (info->precision == MISSING))
		chartoprint = '0';
	else
		chartoprint = ' ';
	len = ft_hexlen(ptr) - ((ptr > 0) ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	if ((len >= info->width) && (info->width <= info->precision))
		spacestoprint = 0;
	else if (info->precision == MISSING)
		spacestoprint = info->width - len;
	else
	{
		spacestoprint = info->width;
		spacestoprint -= ((info->precision > 0) ? info->precision : 0);
	}
	if ((info->width > 0) && (info->precision == 0))
		spacestoprint++;
	if (info->leftJustify == FALSE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
	i = 0;
	if ((info->precision > 0) && (info->precision >= len))
		while (i++ < (info->precision - len))
			write(1, "0", 1);
	if (info->precision != 0)
	{
		if (ptr == 0)
			write(1, "0", 1);
		else
			ft_putnbr_hex_lower(ptr);
	}
	if (info->leftJustify == TRUE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
}

void	print_upper_x_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int				i;
	int				len;
	int				spacestoprint;
	char			chartoprint;

	ptr = (size_t)va_arg(ap, unsigned int);
	if ((info->zero == TRUE) && (info->precision == MISSING))
		chartoprint = '0';
	else
		chartoprint = ' ';
	len = ft_hexlen(ptr) - ((ptr > 0) ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	if ((len >= info->width) && (info->width <= info->precision))
		spacestoprint = 0;
	else if (info->precision == MISSING)
		spacestoprint = info->width - len;
	else
	{
		spacestoprint = info->width;
		spacestoprint -= ((info->precision > 0) ? info->precision : 0);
	}
	if ((info->width > 0) && (info->precision == 0))
		spacestoprint++;
	if (info->leftJustify == FALSE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
	i = 0;
	if ((info->precision > 0) && (info->precision >= len))
		while (i++ < (info->precision - len))
			write(1, "0", 1);
	if (info->precision != 0)
	{
		if (ptr == 0)
			write(1, "0", 1);
		else
			ft_putnbr_hex(ptr);
	}
	if (info->leftJustify == TRUE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
}

void	print_p_specifier(t_parameters *info, va_list ap)
{
	size_t	ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = (size_t)va_arg(ap, void *);
	chartoprint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_hexlen(ptr) + 1;
	else
		len = info->precision;
	if (len >= info->width)
		spacestoprint = 0;
	else
		spacestoprint = info->width - len;
	(!ptr) ? spacestoprint-- : 0;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacestoprint)
			write(1, &chartoprint, 1);
	ft_putstr_fd("0x", 1);
	(!ptr) ? ft_putstr_fd("0", 1) : ft_putnbr_hex_lower(ptr);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacestoprint)
			write(1, &chartoprint, 1);
}
