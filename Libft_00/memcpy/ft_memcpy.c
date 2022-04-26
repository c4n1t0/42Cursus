/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:00:08 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/21 09:05:00 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*q;

	q = src;
	p = dest;
	while (n > 0)
	{
		*p = *q;
		p++;
		q++;
		n--;
	}
	return (dest);
}
