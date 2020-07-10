/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:45:52 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 07:38:17 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an integer of base 10 into a hexadecimal base.
** Prints the result in lowercase.
*/

void	ft_putnbr_hex_lower(size_t nbr)
{
	size_t	mod;

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
