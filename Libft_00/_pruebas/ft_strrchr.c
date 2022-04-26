/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:51:55 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/26 17:47:52 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 1;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	while (count > 0)
	{
		if (*s == c)
			return ((char *)s);
		else
		{
			s--;
			count--;
		}
	}
	return (NULL);
}
