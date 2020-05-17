/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:57:23 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/28 11:48:47 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (n && (*cs1 != '\0') && (*cs2 != '\0') && (*cs1 == *cs2))
	{
		cs1++;
		cs2++;
		n--;
	}
	if (n != 0 && *cs1 != *cs2)
		return ((int)(*cs1 - *cs2));
	return (0);
}
