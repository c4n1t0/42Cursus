/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:34:56 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/26 23:11:26 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*q;
	int		i;

	i = 0;
	q = (char *)s + start;
	while (len > i)
	{
		q++;
		i++;
	}
	p = malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	q = q - i;
	i = 0;
	while (len > i)
	{
		p[i] = q[i];
		i++;
	}
	return (p);
}
