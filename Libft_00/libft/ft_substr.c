/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:34:56 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/13 00:14:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	slen;
	unsigned int	i;

	i = 0;
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, 1));
	if (len > (slen - start))
		len = slen - start;
	p = ft_calloc((len + 1), sizeof(*s));
	if (!p)
		return (NULL);
	while (len > i && start < slen && s[start])
	{
		p[i] = s[start];
		i++;
		start++;
	}
	return (p);
}
