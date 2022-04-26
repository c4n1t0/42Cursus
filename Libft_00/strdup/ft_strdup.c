/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:35:24 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/26 10:42:56 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s != '\0')
	{
		str[i] = *s;
		s++;
		i++;
	}
	return (str);
}
