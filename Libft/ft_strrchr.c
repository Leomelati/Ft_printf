/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:49:42 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/10 12:04:36 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s;
	cs2 = (unsigned char *)s;
	while (*cs1 != '\0')
		cs1++;
	if (c == '\0')
		return ((char *)cs1);
	while (*cs1 != (unsigned char)c && *cs1 != *cs2)
	{
		cs1--;
		if (*cs1 == (unsigned char)c)
			return ((char *)cs1);
	}
	return (0);
}
