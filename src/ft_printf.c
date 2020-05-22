/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/05/22 04:34:32 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_lower(int nbr)
{
	int mod;

	if (nbr > 0)
	{
		mod = nbr % 16;
		if (mod < 10)
			mod += '0';
		else
			mod += 87;
		ft_putnbr_hex(nbr / 16);
		write(1, &mod, 1);
	}
}

int		check_flag(char *letter, va_list ap)
{
	if (*letter == 'c')
	{
		char *ptr = va_arg(ap, char *);
		write(1, &ptr, 1);
	}
	else if (*letter == 's')
	{
		char *ptr = va_arg(ap, char *);
		ft_putstr_fd(ptr, 1);
	}
	else if ((*letter == 'd') | (*letter == 'i'))
	{
		int ptr = va_arg(ap, int);
		ft_putnbr_fd(ptr, 1);
	}
	else if (*letter == 'u')
	{
		unsigned int ptr = va_arg(ap, unsigned int);
		ft_putnbr_uns_fd(ptr, 1);
	}
	else if (*letter == 'x')
	{
		int ptr = va_arg(ap, int);
		ft_putnbr_hex_lower(ptr);
	}
	else if (*letter == 'X')
	{
		int ptr = va_arg(ap, int);
		ft_putnbr_hex(ptr);
	}
	else if (*letter == '%')
		write(1, "%%", 1);
	return (1);
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
			check_flag((char *)format, ap);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}
