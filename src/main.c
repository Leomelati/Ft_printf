/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:11:04 by lmartins          #+#    #+#             */
/*   Updated: 2020/07/07 08:29:53 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int main()
{
	//char char_test = 'H';
	// char *string_test = NULL;
	int 	int_test = 0;
	// int negative_int_test = -42;
	// unsigned int unsigned_test = 4294967295u;

	ft_printf("Printm: \"%.0x\"\n", int_test);
	printf("Printf: \"%.0x\"\n", int_test);
	ft_printf("\n");
	ft_printf("Printm: \"%x\"\n", int_test);
	printf("Printf: \"%x\"\n", int_test);
	ft_printf("\n");
	return (0);
}