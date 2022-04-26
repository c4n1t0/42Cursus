/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:30:40 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 09:36:07 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (*s != '\0' && n > 0)
	{
		if (*s == c)
			return (s);
		else
		{
			s++;
			n--;
		}
	}
	if (*s != '\0')
	{
		while (*s != '\0')
			s++;
	}
	return (s);
}