/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:45:21 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/16 09:47:06 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	justify_padding(int spaces, char c, t_parameters *info, int option)
{
	int i;

	if (info->leftjustify == option)
	{
		i = 0;
		while (i++ < spaces)
		{
			write(1, &c, 1);
			info->result++;
		}
	}
}

void	padding(int spaces, char c, t_parameters *info, char *ptr)
{
	int i;

	((info->precision != MISSING) && (*ptr == '-')) ? spaces++ : 0;
	i = 0;
	while (i++ < spaces)
	{
		write(1, &c, 1);
		info->result++;
	}
}

char	determine_char(t_parameters *info)
{
	if ((info->zero == TRUE) && (info->precision == MISSING))
		return ('0');
	return (' ');
}

int		determine_spaces(int len, t_parameters *info, char *ptr)
{
	int spacestoprint;

	if ((len > info->width) && (info->width != FALSE))
		spacestoprint = 0;
	else if (info->precision == MISSING)
		spacestoprint = info->width - len;
	else
	{
		spacestoprint = info->width;
		spacestoprint -= len;
		spacestoprint -= ((info->precision > 0) ? info->precision : 0);
	}
	((info->width > info->precision) && (info->width >= len)) ? spacestoprint++ : FALSE;
	if ((info->width > 0) && (info->precision == 0) && (*ptr == '0'))
		spacestoprint++;
	return (spacestoprint);
}

int		determine_spaces_hexa(int len, t_parameters *info)
{
	int spacestoprint;

	if (len > info->width)
		spacestoprint = 0;
	else if (info->precision == MISSING)
		spacestoprint = info->width - len;
	else
	{
		spacestoprint = info->width;
		spacestoprint -= len;
		spacestoprint -= ((info->precision > 0) ? info->precision : 0);
	}
	if ((info->width > 0) && (info->precision == 0))
		spacestoprint++;
	return (spacestoprint);
}