/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:32:47 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/28 11:05:03 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cs;
	char	*substring;

	cs = (char *)s;
	if (!(cs))
		return (0);
	if (start > (unsigned int)ft_strlen(cs))
	{
		if (!(substring = malloc(1)))
			return (0);
		substring[0] = '\0';
		return (substring);
	}
	if (!(substring = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len && cs[start])
	{
		substring[i] = cs[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
