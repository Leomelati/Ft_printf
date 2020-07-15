/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:03:06 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/15 09:27:17 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_negative_signal(char *ptr, t_parameters *info, int i)
{
	write(1, "-", 1);
	info->result++;
	i++;
	return (i);
}

int		adjust_width_precision(int len, char *ptr, t_parameters *info)
{
	(*ptr == '-') ? info->width-- : 0;
	return (len);
}

void	print_d_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa(va_arg(ap, int));
	chartoprint = determine_char(info);
	len = ft_strlen(ptr);
	len = adjust_width_precision(len, ptr, info);
	spacestoprint = determine_spaces(len, info, ptr);
	i = 0;
	if ((ptr[i] == '-') && (info->zero == TRUE) && (info->precision == MISSING))
		i = print_negative_signal(ptr, info, i);
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	if ((ptr[i] == '-') && (info->precision != MISSING))
		i = print_negative_signal(ptr, info, i);
	if ((info->precision > 0) && (info->precision >= len))
		padding((info->precision - len), '0', info);
	(ptr[i] == '0' && info->precision == 0) ? 0 : adapted_putstr_fd(&ptr[i], 1, info);
	justify_padding(spacestoprint, chartoprint, info, TRUE);
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
