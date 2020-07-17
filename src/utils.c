/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:45:21 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 08:41:42 by lmartins         ###   ########.fr       */
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

void	padding(int spaces, char c, t_parameters *info)
{
	int i;

	i = 0;
	while (i++ < spaces)
		adapted_putchar_fd(c, 1, info);
}

char	determine_char(t_parameters *info)
{
	(info->zero == TRUE && info->leftjustify == TRUE) ? info->zero = FALSE : 0;
	(info->zero == TRUE && info->precision != MISSING) ? info->zero = FALSE : 0;
	if (info->zero == TRUE)
		return ('0');
	return (' ');
}

void	start_infos(t_parameters *info)
{
	info->zero = FALSE;
	info->leftjustify = FALSE;
	info->width = FALSE;
	info->precision = MISSING;
	info->specifier = FALSE;
	info->result = FALSE;
}

void	restart_infos(t_parameters *info)
{
	info->zero = FALSE;
	info->leftjustify = FALSE;
	info->width = FALSE;
	info->precision = MISSING;
	info->specifier = FALSE;
}
