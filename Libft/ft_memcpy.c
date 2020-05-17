/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:01:43 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/28 12:16:07 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char	*cstr1;
	char	*cstr2;
	size_t	i;

	cstr1 = (char *)str1;
	cstr2 = (char *)str2;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cstr1[i] = cstr2[i];
		i++;
	}
	return (cstr1);
}
