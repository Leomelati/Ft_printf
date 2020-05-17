/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:47:38 by lmartins          #+#    #+#             */
/*   Updated: 2020/02/29 11:16:58 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_up_putnbr(unsigned int n, int fd)
{
	char		num;

	if (n / 10 > 0)
		ft_up_putnbr(n / 10, fd);
	num = n % 10 + '0';
	ft_putchar_fd(num, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1;
	}
	else
		nb = n;
	ft_up_putnbr(nb, fd);
}
