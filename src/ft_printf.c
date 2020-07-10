/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/07/10 05:37:22 by lmartins         ###   ########.fr       */
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
			info->leftJustify = TRUE;
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

void	start_infos(t_parameters *info)
{
	info->signal = FALSE;
	info->zero = FALSE;
	info->leftJustify = FALSE;
	info->width = FALSE;
	info->precision = MISSING;
	info->specifier = FALSE;
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
	if (!ptr)
	{
		ptr = "(null)";
		if (info->precision > MISSING)
			info->precision = (info->precision >= 6) ? 6 : FALSE;
		else
			info->precision = 6;
		
	}
	len = ft_strlen(ptr);
	if ((info->precision < len) && (info->precision != MISSING))
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
	while ((i < len) && (ptr[i] != '\0'))
		write(1, &ptr[i++], 1);
	i = 0;	
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, " ", 1);
}

void	print_d_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = ft_itoa(va_arg(ap, int));
	if ((info->zero == TRUE) && (info->precision == MISSING))
		charToPrint = '0';
	else
		charToPrint = ' ';
	len = ft_strlen(ptr);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	(*ptr == '-') ? len-- : 0;
	(*ptr == '-') ? info->width-- : 0;
	if ((len >= info->width) && (info->width <= info->precision))
		spacesToPrint = 0;
	else if (info->precision == MISSING)
		spacesToPrint = info->width - len;
	else
		spacesToPrint = info->width - ((info->precision > 0) ? info->precision : 0);
	if ((info->width > 0) && (info->precision == 0))
		spacesToPrint++;
	if (info->signal == TRUE)
		write(1, "+", 1);
	if ((*ptr == '-') && (info->zero == TRUE) && (info->precision == MISSING))
	{
		write(1, "-", 1);
		ptr++;
	}	
	if (info->leftJustify == FALSE)
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
	if ((*ptr == '-') && (info->precision != MISSING))
	{
		write(1, "-", 1);
		ptr++;
	}
	i = 0;
	if ((info->precision > 0) && (info->precision >= len))
		while (i++ < (info->precision - len))
			write(1, "0", 1);	
	i = 0;
	while ((ptr[i] != '\0') && (info->precision != 0))
		write(1, &ptr[i++], 1);
	if (info->leftJustify == TRUE)
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
}

void	print_u_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = ft_itoa_uns(va_arg(ap, unsigned int));
	if ((info->zero == TRUE) && (info->precision == MISSING))
		charToPrint = '0';
	else
		charToPrint = ' ';
	len = ft_strlen(ptr);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	if ((len >= info->width) && (info->width <= info->precision))
		spacesToPrint = 0;
	else if (info->precision == MISSING)
		spacesToPrint = info->width - len;
	else
		spacesToPrint = info->width - ((info->precision > 0) ? info->precision : 0);
	if ((info->width > 0) && (info->precision == 0))
		spacesToPrint++;
	if (info->signal == TRUE)
		write(1, "+", 1);
	if (info->leftJustify == FALSE)
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
	i = 0;
	if ((info->precision > 0) && (info->precision >= len))
		while (i++ < (info->precision - len))
			write(1, "0", 1);	
	i = 0;
	while ((ptr[i] != '\0') && (info->precision != 0))
		write(1, &ptr[i++], 1);
	if (info->leftJustify == TRUE)
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
}

void	print_x_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = (size_t)va_arg(ap, unsigned int);
	if ((info->zero == TRUE) && (info->precision == MISSING))
		charToPrint = '0';
	else
		charToPrint = ' ';
	len = ft_hexlen(ptr) - ((ptr > 0) ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	if ((len >= info->width) && (info->width <= info->precision))
		spacesToPrint = 0;
	else if (info->precision == MISSING)
		spacesToPrint = info->width - len;
	else
		spacesToPrint = info->width - ((info->precision > 0) ? info->precision : 0);
	if ((info->width > 0) && (info->precision == 0))
		spacesToPrint++;
	if (info->leftJustify == FALSE)
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
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
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
}

void	print_X_specifier(t_parameters *info, va_list ap)
{
	unsigned int	ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	ptr = (size_t)va_arg(ap, unsigned int);
	if ((info->zero == TRUE) && (info->precision == MISSING))
		charToPrint = '0';
	else
		charToPrint = ' ';
	len = ft_hexlen(ptr) - ((ptr > 0) ? 1 : 0);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	if ((len >= info->width) && (info->width <= info->precision))
		spacesToPrint = 0;
	else if (info->precision == MISSING)
		spacesToPrint = info->width - len;
	else
		spacesToPrint = info->width - ((info->precision > 0) ? info->precision : 0);
	if ((info->width > 0) && (info->precision == 0))
		spacesToPrint++;
	if (info->leftJustify == FALSE)
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
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
		while (0 < spacesToPrint--)
			write(1, &charToPrint, 1);
}

void	print_p_specifier(t_parameters *info, va_list ap)
{
	size_t	ptr;
	int		i;
	int		len;
	int		spacesToPrint;
	char	charToPrint;

	if (ptr = (size_t)va_arg(ap, void *))
	{
		charToPrint = (info->zero == TRUE) ? '0' : ' ';
		if (info->precision == MISSING)
			len = ft_hexlen(ptr) + 1;
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
		ft_putstr_fd("0x", 1);
		ft_putnbr_hex_lower(ptr);
		i = 0;
		if (info->leftJustify == TRUE)
			while (i++ < spacesToPrint)
				write(1, &charToPrint, 1);
	}
	else
		ft_putstr_fd("(nil)", 1);
}

void	print_percentage_specifier(t_parameters *info)
{
	int		i;
	char	charToPrint;
	int		spacesToPrint;

	charToPrint = (info->zero == TRUE) ? '0' : ' ';
	if (1 >= info->width)
		spacesToPrint = 0;
	else
		spacesToPrint = info->width - 1;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
	write(1, "%%", 1);
	i = 0;	
	if (info->leftJustify == TRUE)
		while (i++ < spacesToPrint)
			write(1, &charToPrint, 1);
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
		print_X_specifier(info, ap);
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
	while (info.format[info.i] != '\0')
	{
		if (info.format[info.i] == '%')
		{
			info.i++;
			start_infos(&info);
			if (ft_strchr(FLAGS, info.format[info.i]))
				check_flag(&info);
			if ((ft_isdigit(info.format[info.i])) || (info.format[info.i] == '*'))
				check_width(&info, ap);
			if (info.format[info.i] == '.')
				check_precision(&info, ap);
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
