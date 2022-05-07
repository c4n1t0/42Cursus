/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:45:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/05 14:55:40 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ini(char const *s1, char const *set)
{
	char	*s;
	char	*n;

	s = (char *)set;
	n = (char *)s1;
	while (*s != '\0')
	{
		if (*n == *s)
		{
			n++;
			s = (char *)set;
		}
		else
			s++;
	}
	return (n);
}

void	*ft_fin(char const *s1, char const *set)
{
	char	*s;
	char	*x;

	x = (char *)s1;
	s = (char *)set;
	while (*x != '\0')
		x++;
	x--;
	while (*s != '\0')
	{
		if (*x == *s)
		{
			x--;
			s = (char *)set;
		}
		else
			s++;
	}
	x++;
	*x = '\0';
	return (x);
}

int	ft_long(char *p)
{
	int		i;
	char	*x;

	x = p;
	i = 1;
	while (*x != '\0')
	{
		x++;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*x;
	int		i;

	if (!s1)
		return (NULL);
	p = ft_ini(s1, set);
	ft_fin(s1, set);
	i = ft_long(p);
	x = malloc(i * sizeof(char));
	if (!x)
		return (NULL);
	i = 0;
	while (*p != '\0')
	{
		x[i] = *p;
		i++;
		p++;
	}
	x[i] = '\0';
	return (x);
}
