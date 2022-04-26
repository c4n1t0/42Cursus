/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainStrlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:40:01 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/24 09:27:42 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(void)
{
	char dst[50] = "r";
	const char src[50] = "lorem";
	char dst1[50] = "r";
	const char src1[50] = "lorem";
	int size;
	int x;
	int x1;

	size = 15;

	printf("Antes de copiar 	src = %s    dest = %s\n\n", src, dst);
	x1 = strncpy(dst1, src1, size);

	printf("Despúes de copiar la original src = %s	dest = %s\n\n", src1, dst1);
	printf("longitud %d\n", x1);
	x = ft_strlcpy(dst, src, size);
	printf("Despúes de copiar la mia      src = %s	dest = %s\n\n", src, dst);
	printf("longitud %d\n", x);
	return (0);
}