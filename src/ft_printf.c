/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:37:09 by user42            #+#    #+#             */
/*   Updated: 2020/05/21 05:35:54 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     check_flag(char *letter, va_list ap)
{
	
	if (*letter == 'c')
	{
		char *ptr = va_arg(ap, char *);
		write(1, &ptr, sizeof(ptr));
		// printf("%c\n", va_arg(ap, int));
	}
	return (1);
}

int     ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format  == '%')
		{
			format++;
			check_flag((char *)format, ap);
		}
		else
			write(1,format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}
