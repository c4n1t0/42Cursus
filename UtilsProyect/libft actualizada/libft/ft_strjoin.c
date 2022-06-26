/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:14:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/26 23:42:25 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lp;
	char	*p;
	int		i;

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
