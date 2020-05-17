/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:01:06 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:31 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
		start++;
	end = ft_strlen(&s1[start]);
	if (end > 0)
	{
		while ((s1[start + end - 1]) &&
			(ft_strchr(set, s1[start + end - 1]) != NULL))
			end--;
	}
	return (ft_substr(s1, start, end));
}
