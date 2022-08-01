/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:17:11 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/09 12:19:43 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*p;
	const char	*q;
	size_t		st;

	p = str1;
	q = str2;
	st = 0;
	if (str1 < str2)
	{
		while (st < n)
		{
			p[st] = q[st];
			st++;
		}
	}
	else if (str1 > str2)
	{
		while (n > 0)
		{
			p[n - 1] = q[n - 1];
			n--;
		}
	}
	return (str1);
}
