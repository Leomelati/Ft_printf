/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:04:16 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 08:43:32 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_base(va_arg(ap, unsigned int), 16);
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	spacestoprint = (info->precision > len) ? info->precision : len;
	chartoprint = determine_char(info);
	(info->leftjustify == TRUE) ? print_int(len, info, ptr) : FALSE;
	padding(info->width - spacestoprint, chartoprint, info);
	(info->leftjustify == FALSE) ? print_int(len, info, ptr) : FALSE;
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
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	spacestoprint = (info->precision > len) ? info->precision : len;
	chartoprint = determine_char(info);
	(info->leftjustify == TRUE) ? print_int(len, info, ptr) : FALSE;
	padding(info->width - spacestoprint, chartoprint, info);
	(info->leftjustify == FALSE) ? print_int(len, info, ptr) : FALSE;
	free(ptr);
}

void	print_p_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_base((size_t)va_arg(ap, void *), 16);
	(info->precision >= 0 && info->zero == TRUE) ? info->zero = FALSE : 0;
	len = (*ptr == '0' && info->precision == 0) ? 0 : ft_strlen(ptr);
	spacestoprint = (info->precision > len) ? info->precision : len;
	spacestoprint -= len;
	chartoprint = (info->zero == TRUE) ? '0' : ' ';
	if (info->leftjustify == TRUE)
	{
		adapted_putstr_fd("0x", 1, info);
		justify_padding(spacestoprint, '0', info, TRUE);
		(len == 0 && *ptr == '0') ? 0 : adapted_putstr_fd(ptr, 1, info);
	}
	padding(info->width - (2 + len), chartoprint, info);
	if (info->leftjustify == FALSE)
	{
		adapted_putstr_fd("0x", 1, info);
		justify_padding(spacestoprint, '0', info, FALSE);
		(len == 0 && *ptr == '0') ? 0 : adapted_putstr_fd(ptr, 1, info);
	}
	free(ptr);
}
