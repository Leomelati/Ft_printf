/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:57:22 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/28 11:49:23 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	char	*cstr;
	char	*clittle;

	cstr = (char *)str;
	clittle = (char *)little;
	if (!(*clittle))
		return (cstr);
	i = 0;
	while (i < len && cstr[i] != '\0')
	{
		if (cstr[i] == clittle[0])
		{
			c = 1;
			while (cstr[i + c] == little[c] && little[c] != '\0' &&
				(i + c) < len)
				c++;
			if (little[c] == '\0')
				return (&cstr[i]);
		}
		i++;
	}
	return (0);
}
