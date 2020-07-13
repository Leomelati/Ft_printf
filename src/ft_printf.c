/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/07/13 07:42:57 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_infos(t_parameters *info)
{
	info->zero = FALSE;
	info->leftjustify = FALSE;
	info->width = FALSE;
	info->precision = MISSING;
	info->specifier = FALSE;
	info->result = FALSE;
}

void	restart_infos(t_parameters *info)
{
	info->zero = FALSE;
	info->leftjustify = FALSE;
	info->width = FALSE;
	info->precision = MISSING;
	info->specifier = FALSE;
}

void	prepare_infos(t_parameters *info, va_list ap)
{
	int temp;

	temp = info->i;
	if (ft_strchr(FLAGS, info->format[info->i]))
		check_flag(info);
	if ((ft_isdigit(info->format[info->i])) ||
			(info->format[info->i] == '*'))
		check_width(info, ap);
	if (info->format[info->i] == '.')
		check_precision(info, ap);
	info->specifier = info->format[info->i];
	if (!(ft_strchr(SPECIFIERS, info->specifier)))
		info->i = temp - 1;
}

void	mount_result(t_parameters *info, va_list ap)
{
	char c;

	c = info->format[info->i];
	if (c == 'c')
		print_c_specifier(info, ap);
	else if (c == 's')
		print_s_specifier(info, ap);
	else if ((c == 'd') || (c == 'i'))
		print_d_specifier(info, ap);
	else if (c == 'u')
		print_u_specifier(info, ap);
	else if (c == 'x')
		print_x_specifier(info, ap);
	else if (c == 'X')
		print_upper_x_specifier(info, ap);
	else if (c == 'p')
		print_p_specifier(info, ap);
	else if (c == '%')
		print_percentage_specifier(info);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_parameters	info;

	va_start(ap, format);
	info.format = format;
	info.i = 0;
	start_infos(&info);
	while (info.format[info.i] != '\0')
	{
		if (info.format[info.i] == '%')
		{
			info.i++;
			restart_infos(&info);
			prepare_infos(&info, ap);
			if (ft_strchr(SPECIFIERS, info.specifier))
				mount_result(&info, ap);
			else
				adapted_putchar_fd(info.format[info.i], 1, &info);
		}
		else
			adapted_putchar_fd(info.format[info.i], 1, &info);
		info.i++;
	}
	va_end(ap);
	return (info.result);
}
