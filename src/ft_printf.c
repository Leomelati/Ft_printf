/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/05/27 07:08:28 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_lower(size_t nbr)
{
	size_t mod;

	if (nbr > 0)
	{
		mod = nbr % 16;
		if (mod < 10)
			mod += '0';
		else
			mod += ('a' - 10);
		ft_putnbr_hex_lower(nbr / 16);
		write(1, &mod, 1);
	}
}

int	flag_zero_int(unsigned int size, va_list ap)
{
	int digits;
	int nbr;
	int temp;

	nbr = (int)va_arg(ap, int);
	temp = nbr;
	digits = 0;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	size -= digits;
	while (size != 0)
	{
		write(1, "0", 1);
		size--;
	}
	ft_putnbr_fd(nbr, 1);
	return(++digits);
}

int	flag_zero_uns(unsigned int size, va_list ap)
{
	int digits;
	unsigned int nbr;
	unsigned int temp;

	nbr = (unsigned int)va_arg(ap, int);
	temp = nbr;
	digits = 0;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	size -= digits;
	while (size != 0)
	{
		write(1, "0", 1);
		size--;
	}
	ft_putnbr_uns_fd(nbr, 1);
	return(++digits);
}

// Flag "0" funciona com:
// d
// i
// u
// x
// X

void	flag_zero(char *format, va_list ap)
{
	unsigned int size;

	size = ft_atoi(format);
	while(ft_isdigit(*format) == 1)
		format++;
	if ((*format == 'd') | (*format == 'i'))
		flag_zero_int(size, ap);
	else if (*format == 'u')
		flag_zero_uns(size, ap);
}

void	check_flag(char *format, va_list ap)
{
	if (*format == '0')
		flag_zero(format, ap);
}

void	check_conversion(char *format, va_list ap)
{
	char *ptr;

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
	va_list ap;
	
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			check_conversion((char *)format, ap);
			check_flag((char *)format, ap);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}
