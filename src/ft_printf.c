/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/05/23 07:07:59 by lmartins         ###   ########.fr       */
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

int		check_flag(char *letter, va_list ap)
{
	char *ptr;

	if (*letter == 'c')
	{
		ptr = va_arg(ap, char *);
		write(1, &ptr, 1);
	}
	else if (*letter == 's')
		ft_putstr_fd((char *)va_arg(ap, char *), 1);
	else if ((*letter == 'd') | (*letter == 'i'))
		ft_putnbr_fd((int)va_arg(ap, int), 1);
	else if (*letter == 'u')
		ft_putnbr_uns_fd((unsigned int)va_arg(ap, unsigned int), 1);
	else if (*letter == 'x')
		ft_putnbr_hex_lower((int)va_arg(ap, int));
	else if (*letter == 'X')
		ft_putnbr_hex((int)va_arg(ap, int));
	else if (*letter == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_hex_lower((size_t)va_arg(ap, void *));
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
