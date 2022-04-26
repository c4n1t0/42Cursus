/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:43:26 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 12:08:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*p;
	int		mem;

	mem = 0;
	p = str;
	while (n > 0)
	{
		if (*p == '\0')
			mem = 1;
		*p = c;
		p++;
		n--;
	}
	if (mem == 1)
		*p = '\0';
	return (str);
}
