/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:58:52 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/05 12:37:03 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_count;
	size_t	src_count;
	size_t	i;
	size_t	j;

	dest_count = ft_strlen(dest);
	src_count = ft_strlen(src);
	if (size <= dest_count)
		return (src_count + size);
	i = 0;
	j = dest_count;
	while (src[i] != '\0' && size != '\0' && j < (size - 1))
	{
		dest[j] = (char)src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (src_count + dest_count);
}
