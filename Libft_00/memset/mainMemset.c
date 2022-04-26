/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:33:13 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 12:07:31 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n);

int	main(void)
{
	char str[50] = "hola malaga";
	char str1[50] = "hola malaga";
	int c;
	size_t n;

	c = 'L';
	n = 5;
	printf("mi frase antes es: %s\n\n", str);
	ft_memset(str, c, n);
	memset(str1, c, n);
	printf("Mi funcion devuelve          = %s\n", str);
	printf("La funcion original devuelve = %s\n", str1);
}