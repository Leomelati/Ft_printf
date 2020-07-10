/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:01:34 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 08:45:54 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		spacestoprint;

	ptr = va_arg(ap, char *);
	(!ptr) ? ptr = "(null)" : FALSE;
	len = ft_strlen(ptr);
	if ((info->precision < len) && (info->precision != MISSING))
		len = info->precision;
	if (len >= info->width)
		spacestoprint = 0;
	else
		spacestoprint = info->width - len;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacestoprint)
			write(1, " ", 1);
	i = 0;
	while ((i < len) && (ptr[i] != '\0'))
		write(1, &ptr[i++], 1);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacestoprint)
			write(1, " ", 1);
}

void	print_percentage_specifier(t_parameters *info)
{
	int		i;
	char	chartoprint;
	int		spacestoprint;

	if ((info->zero == TRUE) && (info->leftJustify) == FALSE)
		chartoprint = '0';
	else
		chartoprint = ' ';
	if (1 >= info->width)
		spacestoprint = 0;
	else
		spacestoprint = info->width - 1;
	i = 0;
	if (info->leftJustify == FALSE)
		while (i++ < spacestoprint)
			write(1, &chartoprint, 1);
	write(1, "%%", 1);
	i = 0;
	if (info->leftJustify == TRUE)
		while (i++ < spacestoprint)
			write(1, &chartoprint, 1);
}
