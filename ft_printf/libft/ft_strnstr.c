/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:58:15 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/09 12:20:33 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	count;

	while ((*s1 != '\0' && len > 0) || *s2 == '\0')
	{
		if (*s1 == *s2 || *s2 == '\0')
		{
			count = 0;
			while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && len > 0)
			{
				s1++;
				s2++;
				len--;
				count++;
			}
			if (*s2 == '\0')
				return ((char *)s1 - count);
			s1 = s1 - count;
			s2 = s2 - count;
			len = len + count;
		}
		s1++;
		len--;
	}
	return (NULL);
}
