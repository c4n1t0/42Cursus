/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMemmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:54:48 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/22 12:11:46 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *str1, const void *str2, size_t n);

int	main(void)
{
	const char asd[] = "Chumbo";
	char dest[] = "hola";

	const char src[] = "Malaga";
	char dest1[] = "hola";
	const char src1[] = "malaga";
	int n;

	n = 5;
	printf("Before dest = %s,    src = %s\n", dest1, src1);
	memmove(dest1, src1, n);
	printf("After memmove     dest = %s, src = %s\n", dest1, src1);
	ft_memmove(dest, src, n);
	printf("After ft_memmove  dest = %s, src = %s\n", dest, src);
	return (0);
}