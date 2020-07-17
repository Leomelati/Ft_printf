/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:03:06 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 06:58:28 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_negative(int len, t_parameters *info, char *ptr)
{
	int		negative;

	negative = 0;
	if (*ptr == '-')
	{
		negative = 1;
		adapted_putchar_fd('-', 1, info);
	}
	padding(info->precision - len, '0', info);
	((info->precision == 0) && (*ptr == '0')) ? 0 : adapted_putstr_fd(ptr + negative, 1, info);
}

void	print_d_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		negative;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa(va_arg(ap, int));
	negative = (*ptr == '-') ? TRUE : FALSE;
	chartoprint = determine_char(info);
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	(negative && info->precision>1) ? info->precision++ : 0;
	spacestoprint = (info->precision > len) ? info->precision : len;
	(info->leftjustify == TRUE) ? check_negative(len, info, ptr) : FALSE;
	if (chartoprint == '0' && negative)
		adapted_putchar_fd('-', 1, info);
	else
		negative = 0;
	padding(info->width - spacestoprint, chartoprint, info);
	(info->leftjustify == FALSE) ? check_negative(len, info, ptr) : FALSE;
	free(ptr);
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
	spacestoprint = determine_spaces(len, info, ptr);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0', info);
	(ptr[0] == '0' && info->precision == 0) ? 0 : adapted_putstr_fd(ptr, 1, info);
	justify_padding(spacestoprint, chartoprint, info, TRUE);
	free(ptr);
}
