/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:03:06 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 08:04:59 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa(va_arg(ap, int));
	if ((info->zero == TRUE) && (info->precision == MISSING))
		chartoprint = '0';
	else
		chartoprint = ' ';
	len = ft_strlen(ptr);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	(*ptr == '-') ? len-- : 0;
	(*ptr == '-') ? info->width-- : 0;
	if ((len >= info->width) && (info->width <= info->precision))
		spacestoprint = 0;
	else if (info->precision == MISSING)
		spacestoprint = info->width - len;
	else
	{
		spacestoprint = info->width;
		spacestoprint -= ((info->precision > 0) ? info->precision : 0);
	}
	if ((info->width > 0) && (info->precision == 0))
		spacestoprint++;
	if (info->signal == TRUE)
		write(1, "+", 1);
	if ((*ptr == '-') && (info->zero == TRUE) && (info->precision == MISSING))
	{
		write(1, "-", 1);
		ptr++;
	}
	if (info->leftJustify == FALSE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
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
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
}

void	print_u_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = ft_itoa_uns(va_arg(ap, unsigned int));
	if ((info->zero == TRUE) && (info->precision == MISSING))
		chartoprint = '0';
	else
		chartoprint = ' ';
	len = ft_strlen(ptr);
	if ((len > info->precision) && (info->precision != MISSING))
		info->width--;
	if ((len >= info->width) && (info->width <= info->precision))
		spacestoprint = 0;
	else if (info->precision == MISSING)
		spacestoprint = info->width - len;
	else
	{
		spacestoprint = info->width;
		spacestoprint -= ((info->precision > 0) ? info->precision : 0);
	}
	if ((info->width > 0) && (info->precision == 0))
		spacestoprint++;
	if (info->signal == TRUE)
		write(1, "+", 1);
	if (info->leftJustify == FALSE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
	i = 0;
	if ((info->precision > 0) && (info->precision >= len))
		while (i++ < (info->precision - len))
			write(1, "0", 1);
	i = 0;
	while ((ptr[i] != '\0') && (info->precision != 0))
		write(1, &ptr[i++], 1);
	if (info->leftJustify == TRUE)
		while (0 < spacestoprint--)
			write(1, &chartoprint, 1);
}
