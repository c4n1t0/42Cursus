/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:45:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/27 00:32:40 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char *p;
	char *q;
	char *x;
	int i;
	int count;

	count = 0;
	x = (char *)set;
	p = (char *)s1;
	q = (char *)s1 + ft_strlen(s1);
	while (*x != '\0')
	{
		if (*p == *x)
			p++;
		if (*q == *x)
			q--;
		x++;
	}
	x = p;
	while (x != q)
	{
		i++;
		x++;
	}
	x = ft_calloc(i, sizeof(char));
	if (!x)
		return (NULL);
	while (i > 0)
	{
		x[count] = p[count];
		count++;
		i--;
	}
	return (x);
}