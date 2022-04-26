/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:36:48 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 10:41:42 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = s1;
	q = s2;
	if (n == 0)
		return (0);
	while (*p == *q && n > 0)
	{
		p++;
		q++;
		n--;
	}
	return (*p - *q);
}
