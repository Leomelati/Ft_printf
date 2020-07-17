/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 05:48:04 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/17 08:27:20 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(size_t nb, int base)
{
	char	*str;
	size_t	tmp;
	size_t	i;

	tmp = nb;
	i = 1;
	while ((tmp /= base) >= 1)
		i++;
	if (!(str = (char *)malloc((i + 1) * sizeof(*str))))
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		if (nb % base < 10)
			str[i] = nb % base + '0';
		else
			str[i] = nb % base + 'a' - 10;
		nb /= base;
	}
	return (str);
}
