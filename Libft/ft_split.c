/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:30:35 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/29 11:17:16 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	qnt;
	size_t	i;

	qnt = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != '\0')
	{
		qnt++;
		i++;
	}
	return (qnt);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	k;

	array = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!array || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_word_count(s, c))
	{
		k = 0;
		array[i] = (char *)malloc((ft_word_len(&s[j], c) + 1) * sizeof(char));
		if (!array[i])
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] && s[j] != c)
			array[i][k++] = s[j++];
		array[i][k] = '\0';
		i++;
	}
	array[i] = 0;
	return (array);
}
