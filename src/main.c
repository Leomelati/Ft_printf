/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:11:04 by lmartins          #+#    #+#             */
/*   Updated: 2020/05/23 06:27:15 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int main()
{
    char char_test = 'H';
    char *string_test = "Lorem Ipsum";
    int int_test = 42;
    int negative_int_test = -42;
    unsigned int unsigned_test = 4200000000;

    ft_printf("Ft_Printf: Testando normal\n");
    printf("Printf: Testando normal\n");
    ft_printf("\n");
    ft_printf("Ft_Printf: TESTANDO NORMAL\n");
    printf("Printf: TESTANDO NORMAL\n");
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag C: %c\n", char_test);
    printf("Printf: Testando Flag C: %c\n", char_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag S: %s\n", string_test);
    printf("Printf: Testando Flag S: %s\n", string_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag P: %p\n", &string_test);
    printf("Printf: Testando Flag P: %p\n", &string_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag D: %d\n", int_test);
    printf("Printf: Testando Flag D: %d\n", int_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag I: %i\n", int_test);
    printf("Printf: Testando Flag I: %i\n", int_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag D: %d\n", negative_int_test);
    printf("Printf: Testando Flag D: %d\n", negative_int_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag I: %i\n", negative_int_test);
    printf("Printf: Testando Flag I: %i\n", negative_int_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag U: %u\n", unsigned_test);
    printf("Printf: Testando Flag U: %u\n", unsigned_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag x: %x\n", int_test);
    printf("Printf: Testando Flag x: %x\n", int_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando Flag X: %X\n", int_test);
    printf("Printf: Testando Flag X: %X\n", int_test);
    ft_printf("\n");
    ft_printf("Ft_Printf: Testando 2%%\n");
    printf("Printf: Testando 2%%\n");
    ft_printf("\n");
    // ft_printf("Ft_Printf: Testando as flags C: %c | S: %s | P: %p | D: %d | I: %i | U: %u | x: %x | X: %X | 2%%\n", char_test, string_test, string_test, int_test, int_test, unsigned_test, int_test, int_test);
    // printf("Printf: Testando as flags C: %c | S: %s | P: %p | D: %d | I: %i | U: %u | x: %x | X: %X | 2%%\n", char_test, string_test, string_test, int_test, int_test, unsigned_test, int_test, int_test);
    return (0);
}