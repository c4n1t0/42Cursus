/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:00:17 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/26 13:53:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = ft_strlen(src);
	if (size > 0)
	{
		while (size - 1 > 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			size--;
		}
		*dst = '\0';
	}
	return (count);
}
