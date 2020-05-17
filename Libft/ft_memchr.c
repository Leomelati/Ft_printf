/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:18:14 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/05 12:32:32 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	if (n != '\0')
		while (n > 0)
		{
			if (*cs++ == (unsigned char)c)
				return ((void *)(cs - 1));
			n--;
		}
	return (0);
}
