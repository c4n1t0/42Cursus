/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:13:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/16 00:36:10 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	src1;
	unsigned long	dst1;
	int				x;

	src1 = ft_strlen(src);
	dst1 = ft_strlen(dst);
	x = dst1;
	if (size <= dst1)
		return (size + src1);
	while (dst1 < (size - 1) && *src != '\0')
	{
		dst[dst1] = *src;
		src++;
		dst1++;
	}
	dst[dst1] = '\0';
	return (src1 + x);
}
