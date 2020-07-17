/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:01:34 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 08:37:42 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adapted_putstr_fd(char *s, int fd, t_parameters *info)
{
	size_t	i;

	if (!(s))
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		info->result++;
		i++;
	}
}

void	adapted_putchar_fd(char c, int fd, t_parameters *info)
{
	if (!(c))
		return ;
	write(fd, &c, 1);
	info->result++;
}

void	print_c_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;

	ptr = va_arg(ap, char *);
	info->width--;
	justify_padding(info->width, ' ', info, FALSE);
	write(1, &ptr, 1);
	info->result++;
	justify_padding(info->width, ' ', info, TRUE);
}

void	print_s_specifier(t_parameters *info, va_list ap)
{
	char	*ptr;
	int		i;
	int		len;
	int		spacestoprint;
	char	chartoprint;

	ptr = va_arg(ap, char *);
	(!ptr) ? ptr = "(null)" : FALSE;
	chartoprint = determine_char(info);
	len = ft_strlen(ptr);
	if ((info->precision < len) && (info->precision != MISSING))
		len = info->precision;
	if (len >= info->width)
		spacestoprint = 0;
	else
		spacestoprint = info->width - len;
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	i = 0;
	while ((i < len) && (ptr[i] != '\0'))
	{
		write(1, &ptr[i++], 1);
		info->result++;
	}
	justify_padding(spacestoprint, ' ', info, TRUE);
}

void	print_percentage_specifier(t_parameters *info)
{
	int		i;
	char	chartoprint;
	int		spacestoprint;

	i = info->i;
	while ((ft_strchr(SPECIFIERS, info->format[i])) &&
		!(ft_isalpha(info->format[i])) && info->format[i + 1])
		i++;
	if ((info->format[i] == '%') && (info->format[info->i] == '%'))
	{
		chartoprint = ((info->zero == TRUE) && (info->leftjustify) == FALSE) ?
			'0' : ' ';
		spacestoprint = (1 >= info->width) ? 0 : info->width - 1;
		justify_padding(spacestoprint, chartoprint, info, FALSE);
		write(1, "%%", 1);
		info->result++;
		justify_padding(spacestoprint, chartoprint, info, TRUE);
	}
	else
	{
		write(1, "%%", 1);
		info->result++;
	}
}
