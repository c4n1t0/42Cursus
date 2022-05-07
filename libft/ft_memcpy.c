/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:00:08 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/05 18:29:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*q;

	q = src;
	p = dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0 && *q != '\0')
	{
		*p = *q;
		p++;
		q++;
		n--;
	}
	return (dest);
}
