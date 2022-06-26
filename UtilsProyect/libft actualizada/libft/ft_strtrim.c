/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:45:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/12 14:22:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	x;
	size_t	len;

	len = ft_strlen(s1);
	x = 0;
	if (!s1)
		return (NULL);
	while (x < len && ft_strchr(set, s1[x]))
		x++;
	while (len > x && ft_strchr(set, s1[len - 1]))
		len--;
	p = ft_substr(&s1[x], 0, len - x);
	if (!p)
		return (NULL);
	return (p);
}
