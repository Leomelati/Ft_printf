/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/05/29 23:53:58 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_zero_hex_lower(unsigned int size, va_list ap)
{
	int				nbr;
	int				temp;
	unsigned int	digits;

	nbr = (int)va_arg(ap, int);
	temp = nbr;
	digits = 0;
	while (temp > 0)
	{
		temp /= 16;
		digits++;
	}
	if (size < digits)
		size = digits;
	while ((size - digits) != 0)
	{
		write(1, "0", 1);
		size--;
	}
	ft_putnbr_hex_lower(nbr);
	return (++digits);
}

int		flag_zero_hex(unsigned int size, va_list ap)
{
	int				nbr;
	int				temp;
	unsigned int	digits;

	nbr = (int)va_arg(ap, int);
	temp = nbr;
	digits = 0;
	while (temp > 0)
	{
		temp /= 16;
		digits++;
	}
	if (size < digits)
		size = digits;
	while ((size - digits) != 0)
	{
		write(1, "0", 1);
		size--;
	}
	ft_putnbr_hex(nbr);
	return (++digits);
}

int		flag_zero_int(unsigned int size, va_list ap)
{
	unsigned int	digits;
	int				nbr;
	int				temp;

	nbr = (int)va_arg(ap, int);
	temp = nbr;
	digits = 0;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	if (size < digits)
		size = digits;
	if (nbr < 0)
	{
		write(1, "-", 1);
		digits++;
	}
	while ((size - digits) != 0)
	{
		write(1, "0", 1);
		size--;
	}
	if (nbr < 0)
		ft_putnbr_fd((unsigned int)nbr * -1, 1);
	else
		ft_putnbr_fd(nbr, 1);
	return (++digits);
}

int		flag_zero_uns(unsigned int size, va_list ap)
{
	unsigned int	digits;
	unsigned int	nbr;
	unsigned int	temp;

	nbr = (unsigned int)va_arg(ap, int);
	temp = nbr;
	digits = 0;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	if (size < digits)
		size = digits;
	while ((size - digits) != 0)
	{
		write(1, "0", 1);
		size--;
	}
	ft_putnbr_uns_fd(nbr, 1);
	return (++digits);
}

char	*flag_zero(char *format, va_list ap)
{
	unsigned int	size;

	size = ft_atoi(format);
	while (ft_isdigit(*format) == 1)
		format++;
	if ((*format == 'd') | (*format == 'i'))
		flag_zero_int(size, ap);
	else if (*format == 'u')
		flag_zero_uns(size, ap);
	else if (*format == 'x')
		flag_zero_hex_lower(size, ap);
	else if (*format == 'X')
		flag_zero_hex(size, ap);
	return (format);
}

char	*flag_plus(char *format, va_list ap)
{
	int				nbr;
	unsigned int	size;
	va_list			temp;
	
	va_copy(temp, ap);
	nbr = (int)va_arg(ap, int);
	if (nbr >= 0)
		write(1,"+", 1);
	format++;
	if (*format == '0')
	{
		size = ft_atoi(format) - 1;
		while (ft_isdigit(*format) == 1)
			format++;
		flag_zero_int(size, temp);
	}
	else
		ft_putnbr_fd(nbr, 1);
	va_end(temp);
	return (format);
}

char	*check_flag(char *format, va_list ap)
{
	if (*format == '0')
		format = flag_zero(format, ap);
	if (*format == '+')
		format = flag_plus(format, ap);
	return (format);
}

void	check_conversion(char *format, va_list ap)
{
	char	*ptr;

	if (*format == 'c')
	{
		ptr = va_arg(ap, char *);
		write(1, &ptr, 1);
	}
	else if (*format == 's')
		ft_putstr_fd((char *)va_arg(ap, char *), 1);
	else if ((*format == 'd') | (*format == 'i'))
		ft_putnbr_fd((int)va_arg(ap, int), 1);
	else if (*format == 'u')
		ft_putnbr_uns_fd((unsigned int)va_arg(ap, unsigned int), 1);
	else if (*format == 'x')
		ft_putnbr_hex_lower((int)va_arg(ap, int));
	else if (*format == 'X')
		ft_putnbr_hex((int)va_arg(ap, int));
	else if (*format == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_hex_lower((size_t)va_arg(ap, void *));
	}
	else if (*format == '%')
		write(1, "%%", 1);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*cformat;
	unsigned int	i;

	va_start(ap, format);
	cformat = (char *)format;
	i = 0;
	while (cformat[i] != '\0')
	{
		if (cformat[i] == '%')
		{
			i++;
			check_conversion(&cformat[i], ap);
			cformat = check_flag(&cformat[i], ap);
			i = 0;
		}
		else
			write(1, &cformat[i], 1);
		i++;
	}
	va_end(ap);
	return (1);
}
