/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainStrlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:11:50 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/22 10:21:43 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	ft_strlcat(char *dst, const char *src, size_t size);

int	main(void)
{
	char dst[50] = "hola ";
	const char src[50] = "malaga";
	char dst1[50] = "hola ";
	const char src1[50] = "malaga";
	int size;

	size = 50;

	printf("Antes de concatenar 	src = %s    dest = %s\n\n", src, dst);
	strlcat(dst1, src1, size);
	printf("Despúes de concatenar la original src = %s	dest = %s\n\n", src1,
				dst1);
	ft_strlcat(dst, src, size);
	printf("Despúes de concatenar la mia      src = %s	dest = %s\n\n", src,
				dst);
	return (0);
}