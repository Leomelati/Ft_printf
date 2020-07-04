/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/07/04 19:12:04 by lmartins         ###   ########.fr       */
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
		info->leftJustify = TRUE;
		info->i++;
	}
	if (ft_strchr(FLAGS, info->format[info->i]))
		check_flag(info);
}

void	check_width(t_parameters *info)
{
	info->width = ft_atoi(&info->format[info->i]);
	while (ft_isdigit(info->format[info->i]) == 1)
		info->i++;
}

void	check_precision(t_parameters *info)
{
	info->i++;
	info->precision = ft_atoi(&info->format[info->i]);
	while (ft_isdigit(info->format[info->i]) == 1)
		info->i++;
}

void	start_infos(t_parameters *info)
{
	info->signal = FALSE;
	info->zero = FALSE;
	info->leftJustify = FALSE;
	info->width = 0;
	info->precision = MISSING;
	info->specifier = 0;
	info->result = NULL;
}

void	print_c_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = va_arg(ap, char *);
	info->width--;
	if (info->leftJustify == FALSE)
		while (i++ < info->width)
			write(1, " ", 1);
	write(1, &ptr, 1);
	if (info->leftJustify == TRUE)
		while (i++ < info->width)
			write(1, " ", 1);
}

void	print_s_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacesToPrint;

	ptr = va_arg(ap, char *);
	if (info->precision == MISSING)
		len = ft_strlen(ptr);
	else
		len = info->precision;
	if (len >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - len;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, " ", 1);
	i = 0;
	ft_putstr_fd(ptr, 1);
	i = 0;	
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, " ", 1);
}

void	print_d_specifier(t_parameters *info, va_list ap)
{
	int		ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = va_arg(ap, int);
	charToPrint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_intlen(ptr) - info->signal;
	else
		len = info->precision - info->signal;
	if (len >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - len - info->signal;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
	if (info->signal == TRUE)
		write(1, "+", 1);
	ft_putnbr_fd(ptr, 1);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
}

void	print_u_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int				i;
	int				len;
	int				spacesToPrint;
	char			charToPrint;

	ptr = va_arg(ap, unsigned int);
	charToPrint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_intlen(ptr);
	else
		len = info->precision;
	if (len >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - len;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
	ft_putnbr_uns_fd(ptr, 1);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
}

void	print_x_specifier(t_parameters *info, va_list ap)
{
	int		ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = va_arg(ap, int);
	charToPrint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_intlen(ptr);
	else
		len = info->precision;
	if (len >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - len;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
	ft_putnbr_hex_lower(ptr);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
}

void	print_X_specifier(t_parameters *info, va_list ap)
{
	int		ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = va_arg(ap, int);
	charToPrint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_intlen(ptr);
	else
		len = info->precision;
	if (len >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - len;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
	ft_putnbr_hex(ptr);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
}

void	print_p_specifier(t_parameters *info, va_list ap)
{
	size_t	ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = (size_t)va_arg(ap, void *);
	ft_putstr_fd("0x", 1);
	charToPrint = (info->zero == TRUE) ? '0' : ' ';
	if (info->precision == MISSING)
		len = ft_intlen(ptr);
	else
		len = info->precision;
	if (len >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - len;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
	ft_putnbr_hex_lower(ptr);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
}

void	mount_result(t_parameters *info, va_list ap)
{
	if (info->format[info->i] == 'c')
		print_c_specifier(info, ap);
	else if (info->format[info->i] == 's')
		print_s_specifier(info, ap);
	else if ((info->format[info->i] == 'd') ||
		(info->format[info->i] == 'i'))
		print_d_specifier(info, ap);
	else if (info->format[info->i] == 'u')
		print_u_specifier(info, ap);
	else if (info->format[info->i] == 'x')
		print_x_specifier(info, ap);
	else if (info->format[info->i] == 'X')
		print_X_specifier(info, ap);
	else if (info->format[info->i] == 'p')
		print_p_specifier(info, ap);
	else if (info->format[info->i] == '%')
		write(1, "%%", 1);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_parameters	info;

	va_start(ap, format);
	info.format = format;
	info.i = 0;
	while (info.format[info.i] != '\0')
	{
		if (info.format[info.i] == '%')
		{
			info.i++;
			start_infos(&info);
			if (ft_strchr(FLAGS, info.format[info.i]))
				check_flag(&info);
			if (ft_isdigit(info.format[info.i]))
				check_width(&info);
			if (info.format[info.i] == '.')
				check_precision(&info);
			info.specifier = info.format[info.i];
			mount_result(&info, ap);
		}
		else
			write(1, &info.format[info.i], 1);
		info.i++;
	}
	va_end(ap);
	return (1);
}
