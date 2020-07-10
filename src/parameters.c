/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:06:36 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 09:34:00 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(t_parameters *info)
{
	if (info->format[info->i] == '0')
	{
		info->zero = TRUE;
		info->i++;
	}
	if (info->format[info->i] == '+')
	{
		info->signal = TRUE;
		info->i++;
	}
	if (info->format[info->i] == '-')
	{
		info->leftjustify = TRUE;
		info->i++;
	}
	if (info->format[info->i] == ' ')
	{
		write(1, " ", 1);
		info->i++;
	}
	if (ft_strchr(FLAGS, info->format[info->i]))
		check_flag(info);
}

void	check_width(t_parameters *info, va_list ap)
{
	if (info->format[info->i] == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->leftjustify = TRUE;
			info->zero = FALSE;
		}
		info->i++;
	}
	else
		info->width = ft_atoi(&info->format[info->i]);
	while (ft_isdigit(info->format[info->i]) == 1)
		info->i++;
}

void	check_precision(t_parameters *info, va_list ap)
{
	info->i++;
	if (info->format[info->i] == '*')
	{
		info->precision = va_arg(ap, int);
		(info->precision < MISSING) ? info->precision = MISSING : 0;
		info->i++;
	}
	else
		info->precision = ft_atoi(&info->format[info->i]);
	while (ft_isdigit(info->format[info->i]) == 1)
		info->i++;
}
