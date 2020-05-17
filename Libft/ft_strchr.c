/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:27:56 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/07 13:36:25 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*cs;

	i = 0;
	cs = (char *)s;
	while (i <= ft_strlen(cs))
	{
		if (cs[i] == (char)c)
			return (&cs[i]);
		i++;
	}
	return (0);
}
