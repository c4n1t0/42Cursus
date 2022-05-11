/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:30:40 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/11 13:32:42 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0' && n > 0)
	{
		if (*p == (char)c)
			return ((void *)p);
		else
		{
			p++;
			n--;
		}
	}
	if ((char)c == '\0')
		return ((void *)p);
	return (NULL);
}
