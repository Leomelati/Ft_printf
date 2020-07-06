/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:11:04 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/06 06:52:11 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int main()
{
	//char char_test = 'H';
	// char *string_test = NULL;
	int int_test = 34;
	// int negative_int_test = -42;
	// unsigned int unsigned_test = 3000000001;

	ft_printf("Printm: \"%08.5d\"\n", int_test);
	printf("Printf: \"%08.5d\"\n", int_test);
	ft_printf("\n");
	return (0);
}