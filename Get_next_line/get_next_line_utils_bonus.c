/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:47:39 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/29 21:58:25 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = NULL;
	if (nmemb == __SIZE_MAX__ && size > 1)
		return (NULL);
	if (size == __SIZE_MAX__ && nmemb > 1)
		return (NULL);
	p = (void *)malloc(nmemb * size);
	if (!p)
		return (free(p), NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lp;
	char	*p;
	int		i;

	if (!s1)
		s1 = ft_calloc(1, 1);
	lp = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	p = malloc(lp * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1 != '\0')
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		p[i] = *s2;
		i++;
		s2++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
