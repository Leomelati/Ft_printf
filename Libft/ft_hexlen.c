/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 06:27:41 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/10 07:38:07 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an integer of base 10 into a hexadecimal base.
** Return the number of caracters after the conversion.
*/

size_t	ft_hexlen(size_t nbr)
{
	size_t	mod;
	size_t	i;

	i = 1;
	if (nbr > 0)
	{
		mod = nbr % 16;
		if (mod < 10)
			mod += '0';
		else
			mod += ('a' - 10);
		i += ft_hexlen(nbr / 16);
	}
	return (i);
}
