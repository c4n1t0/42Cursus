/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:17:00 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/31 18:00:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int i;
	int x;
	int y;
	int y1;
	int chrln;
	int chrln1;
	char *s;
	char chr;

	chr = 'A';
	s = "asdf";
	i = 5850;
	x = i;
	//decimales
	i = ft_printf("mi contador = %d asdf\n", i);
	ft_printf("mi contador ft_printf = %d\n", i);
	x = printf("mi contador = %d asdf\n", x);
	printf("mi contador printf = %d\n", x);
	ft_printf("mi contador ft_printf = %d\nmi contador printf = %d\n", i, x);

	//Strings
	y = ft_printf("\nMi string: %s\n", s);
	ft_printf("\nMi string contador: %d\n", y);
	y1 = printf("\nMi string: %s\n", s);
	printf("\nMi string contador: %d\n", y1);

	//caracter
	chrln = ft_printf("mi caracter es: %c\n", chr);
	ft_printf("\nLongitud de caracter: %d\n", chrln);
	chrln1 = printf("mi caracter es: %c\n", chr);
	printf("\nLongitud de caracter: %d\n", chrln1);
}