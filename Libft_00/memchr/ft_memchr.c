/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:30:40 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/26 17:41:13 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0' && n > 0)
	{
		if (*p == c)
			return (p);
		else
		{
			p++;
			n--;
		}
	}
	return (NULL);
}
