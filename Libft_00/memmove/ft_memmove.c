/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:17:11 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/22 11:55:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*p;
	const char	*q;

	p = str1;
	q = str2;
	if (str1 < str2)
		q = str2 + n;
	while (n > 0)
	{
		*p = *q;
		p++;
		if (str1 < str2)
			q--;
		else
			q++;
		n--;
	}
	return (str1);
}
