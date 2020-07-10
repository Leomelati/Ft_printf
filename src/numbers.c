/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:03:06 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/11 00:47:16 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_negative_signal(char *ptr, t_parameters *info)
{
	write(1, "-", 1);
	info->result++;
	ptr++;
	return (ptr);
}

int		adjust_width_precision(int len, char *ptr, t_parameters *info)
{
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	(*ptr == '-') ? len-- : 0;
	(*ptr == '-') ? info->width-- : 0;
	return (len);
}

void	print_d_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa(va_arg(ap, int));
	chartoprint = determine_char(info);
	len = ft_strlen(ptr);
	len = adjust_width_precision(len, ptr, info);
	spacestoprint = determine_spaces(len, info);
	if ((*ptr == '-') && (info->zero == TRUE) && (info->precision == MISSING))
		ptr = print_negative_signal(ptr, info);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((*ptr == '-') && (info->precision != MISSING))
		ptr = print_negative_signal(ptr, info);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0', info);
	while ((*ptr != '\0') && (info->precision != 0))
	{
		write(1, ptr, 1);
		info->result++;
		ptr++;
	}
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}

void	print_u_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_uns(va_arg(ap, unsigned int));
	chartoprint = determine_char(info);
	len = ft_strlen(ptr);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	spacestoprint = determine_spaces(len, info);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0', info);
	while ((*ptr != '\0') && (info->precision != 0))
	{
		write(1, ptr, 1);
		info->result++;
		ptr++;
	}
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}
