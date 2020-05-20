/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:18:14 by lmartins          #+#    #+#             */
/*   Updated: 2020/05/20 04:54:13 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;

	cs = (unsigned char *)s;
	if (n != '\0')
		while (n > 0)
		{
			if (*cs++ == (unsigned char)c)
				return ((void *)(cs - 1));
			n--;
		}
	return (0);
}
