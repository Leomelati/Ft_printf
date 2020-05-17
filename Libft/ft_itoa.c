/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 00:24:45 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/29 11:16:41 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(unsigned int n)
{
	int len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	char			*array;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	len = ft_numlen(num) + 1 + ((n < 0) ? 1 : 0);
	if (!(array = (char *)malloc(len * sizeof(char))))
		return (0);
	if (n < 0)
		array[0] = '-';
	array[len - 1] = '\0';
	len -= 2;
	while (num >= 10)
	{
		array[len] = (char)(num % 10) + '0';
		num = num / 10;
		len--;
	}
	array[len] = (char)num % 10 + '0';
	return (array);
}
