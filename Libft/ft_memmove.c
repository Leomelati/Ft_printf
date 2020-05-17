/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:26:53 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/28 12:53:32 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	if (dst == src)
		return (dst);
	if (src > dst)
	{
		dst = ft_memcpy(dst, src, len);
		return (dst);
	}
	cdst = (char *)dst;
	csrc = (char *)src;
	while (len-- > 0)
		cdst[len] = csrc[len];
	return (dst);
}
