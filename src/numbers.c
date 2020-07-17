/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:03:06 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 08:34:07 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int len, t_parameters *info, char *ptr)
{
	int		negative;

	negative = 0;
	if (*ptr == '-')
	{
		negative = 1;
		adapted_putchar_fd('-', 1, info);
	}
	padding(info->precision - len, '0', info);
	((info->precision == 0) && (*ptr == '0')) ?
		0 : adapted_putstr_fd(ptr + negative, 1, info);
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
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	(negative && info->precision > 1) ? info->precision++ : 0;
	spacestoprint = (info->precision > len) ? info->precision : len;
	chartoprint = determine_char(info);
	(info->leftjustify == TRUE) ? print_int(len, info, ptr) : FALSE;
	if (chartoprint == '0' && negative && info->leftjustify == FALSE)
		adapted_putchar_fd('-', 1, info);
	else
		negative = 0;
	padding(info->width - spacestoprint, chartoprint, info);
	(info->leftjustify == FALSE) ? print_int(len, info, ptr + negative) : FALSE;
	free(ptr);
}

void	print_u_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_uns(va_arg(ap, unsigned int));
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	spacestoprint = (info->precision > len) ? info->precision : len;
	chartoprint = determine_char(info);
	(info->leftjustify == TRUE) ? print_int(len, info, ptr) : FALSE;
	padding(info->width - spacestoprint, chartoprint, info);
	(info->leftjustify == FALSE) ? print_int(len, info, ptr) : FALSE;
	free(ptr);
}
