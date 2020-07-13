/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:01:34 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/13 07:50:58 by lmartins         ###   ########.fr       */
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
	size_t	i;

	if (!(c))
		return ;
	write(fd, &c, 1);
	info->result++;
}

void	print_c_specifier(t_parameters *info, va_list ap)
{
	char	ptr;

	ptr = va_arg(ap, int);
	info->width--;
	justify_padding(info->width, ' ', info, FALSE);
	adapted_putchar_fd(ptr, 1, info);
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
	char	chartoprint;
	int		spacestoprint;

	if ((info->zero == TRUE) && (info->leftjustify) == FALSE)
		chartoprint = '0';
	else
		chartoprint = ' ';
	if (1 >= info->width)
		spacestoprint = 0;
	else
		spacestoprint = info->width - 1;
	justify_padding(spacestoprint, chartoprint, info, FALSE);
	write(1, "%%", 1);
	info->result++;
	justify_padding(spacestoprint, chartoprint, info, TRUE);
}
