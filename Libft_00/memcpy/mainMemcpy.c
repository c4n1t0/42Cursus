/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMemcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:51:55 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/21 09:12:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	const char src[50] = "hola malaga";
	char dest[50];
	const char src1[50] = "hola malaga";
	char dest1[50];
	int n;

	n = strlen(src) + 1;
	strcpy(dest, "Heloooo!!");
	strcpy(dest1, "Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest1, src1, n);
	printf("La funcion original = %s\n", dest1);
	ft_memcpy(dest, src, n);
	printf("La funcion nueva    = %s\n", dest);

	return (0);
}