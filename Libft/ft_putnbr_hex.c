/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:51:16 by lmartins          #+#    #+#             */
/*   Updated: 2020/05/22 03:40:36 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an integer of base 10 into a hexadecimal base and prints the result.
*/

void	ft_putnbr_hex(int nbr)
{
	int mod;

	if (nbr > 0)
	{
		mod = nbr % 16;
		if (mod < 10)
			mod += '0';
		else
			mod += 55;
		ft_putnbr_hex(nbr / 16);
		write(1, &mod, 1);
	}
}
