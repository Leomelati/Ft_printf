/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 05:54:51 by lmartins          #+#    #+#             */
/*   Updated: 2020/05/21 05:58:53 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	char		num;

	if (n / 10 > 0)
		ft_putnbr_uns_fd(n / 10, fd);
	num = n % 10 + '0';
	ft_putchar_fd(num, fd);
}
