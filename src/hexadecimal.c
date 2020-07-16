/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:04:16 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/16 09:28:12 by lmartins         ###   ########.fr       */
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
	char	*ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_base(va_arg(ap, unsigned int), 16);
	chartoprint = determine_char(info);
	len = ft_strlen(ptr) - ((*ptr == '-') ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	spacestoprint = determine_spaces_hexa(len, info);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0', info, ptr);
	if (info->precision != 0)
	{
		if (ptr[0] == '0')
		{
			write(1, "0", 1);
			info->result++;
		}
		else
			adapted_putstr_fd(ptr, 1, info);
	}
	justify_padding(spacestoprint, chartoprint, info, TRUE);
	free(ptr);
}

void	print_upper_x_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_base(va_arg(ap, unsigned int), 16);
	i = 0;
	while (ptr[i])
	{
		ptr[i] = toupper((unsigned char)ptr[i]);
		i++;
	}
	chartoprint = determine_char(info);
	len = ft_strlen(ptr) - ((*ptr == '-') ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	spacestoprint = determine_spaces_hexa(len, info);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0', info, ptr);
	if (info->precision != 0)
	{
		if (ptr[0] == '0')
		{
			write(1, "0", 1);
			info->result++;
		}
		else
			adapted_putstr_fd(ptr, 1, info);
	}
	justify_padding(spacestoprint, chartoprint, info, TRUE);
	free(ptr);
}

void	print_p_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_base((size_t)va_arg(ap, void *), 16);
	(info->precision >= 0 && info->zero == TRUE) ? info->zero = FALSE : 0;
	chartoprint = (info->zero == TRUE) ? '0' : ' ';
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	spacestoprint = (info->precision > len) ? info->precision : len;
	spacestoprint -= len;
	if (info->leftjustify == TRUE)
	{
		adapted_putstr_fd("0x", 1, info);
		justify_padding(spacestoprint, '0', info, TRUE);
		(len == 0 && *ptr == '0') ? 0 : adapted_putstr_fd(ptr, 1, info);
	}
	padding(info->width - (2 + len), chartoprint, info, ptr);
	if (info->leftjustify == FALSE)
	{
		adapted_putstr_fd("0x", 1, info);
		justify_padding(spacestoprint, '0', info, FALSE);
		(len == 0 && *ptr == '0') ? 0 : adapted_putstr_fd(ptr, 1, info);
	}
	free(ptr);
}
