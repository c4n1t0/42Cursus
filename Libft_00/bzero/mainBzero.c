/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainBzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:12:02 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 12:30:10 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n);

int	main(void)
{
	char str[50] = "hola malaga";
	char *s;
	char str1[50] = "hola malaga";
	char *s1;
	size_t n;

	n = 10;
	s = str + 4;
	s1 = str1 + 4;
	printf("Mi cadena de entrada es: %s\n\n", str);
	ft_bzero(s, n);
	bzero(s1, n);
	printf("La funcion mia devuelve:      %s\n", str);
	printf("La funcion original devuelve: %s\n", str1);
}