/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:00:17 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/24 09:31:35 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int			count;
	const char	*p;

	count = 0;
	p = src;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	if (size > 0)
	{
		while (size - 1 > 0)
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
