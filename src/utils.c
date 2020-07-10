/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:45:21 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 08:48:16 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding(int spacestoprint, char chartoprint)
{
	int i;

	i = 0;
	while (i++ < spacestoprint)
		write(1, &chartoprint, 1);
}
