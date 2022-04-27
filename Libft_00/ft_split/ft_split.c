/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/27 20:49:16 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_long(char *str)
{
	char	*p;
	int		i;

	i = 0;
	p = str;
	while (*p != '\0')
	{
		i++;
		p++;
	}
	return (i);
}
char	**ft_split(char const *s, char c)
{
	char	*str;
	int		count;

	str = ft_strtrim(s, c);
	printf("Despues del trim: %s\n", str);
	count = ft_long(str);
	printf("La longitud de la cadena es: %d", count);
	return (str);
}

int	main(void)
{
	char const s[] = " hola que tal ";
	char c = ' ';
	char **str;

	str = ft_split(s, c);
}