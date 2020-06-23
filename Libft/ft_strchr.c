/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:27:56 by lmartins          #+#    #+#             */
/*   Updated: 2020/06/23 07:16:43 by lmartins         ###   ########.fr       */
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
