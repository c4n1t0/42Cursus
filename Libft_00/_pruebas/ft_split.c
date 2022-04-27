/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/27 23:24:58 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut(char const *s, char c)
{
	char	*p;

	p = (char *)s;
	while (*s == c)
		s++;
	while (*p != '\0')
		p++;
	p--;
	while (*p == c)
		p--;
	if (*p != '\0')
	{
		p++;
		*p = '\0';
	}
	return ((char *)s);
}

void	ft_reserv(char **x, char *str, char c)
{
	int		i;
	int		o;
	char	*p;

	p = str;
	o = 0;
	while (*p != '\0')
	{
		i = 1;
		while (*p != c && *p != '\0')
		{
			p++;
			i++;
			if (*p == c || *p == '\0')
			{
				x[o] = malloc(i * sizeof(char));
				printf("i = %d\n", i);
				printf("o = %d\n", o);
				o++;
				i = 1 + 1;
			}
		}
		//if (*p != '\0')
		p++;
	}
	printf("reserva realizada o = %d\n", o);
}

char	**ft_distr(char **x, char *str, char c, int count)
{
	int		o;
	int		i;
	char	*p;

	p = str;
	o = 0;
	i = 0;
	while (count > 0)
	{
		x[o][i] = *p;
		if (*p == c || *p == '\0')
		{
			x[o][i] = '\0';
			o++;
		}
		if (*p != '\0')
		{
			i++;
			p++;
		}
		count--;
	}
	o--;
	x[o][i] = '\0';
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**x;
	int		count;

	str = ft_cut(s, c);
	printf("Despues del trim: %s|\n", str);
	count = ft_strlen(str) + 1;
	printf("La longitud de la cadena es: %d\n", count);
	ft_reserv(x, str, c);
	//ft_distr(x, str, c, count);
	//return (x);
}

int	main(void)
{
	char const s[] = " hola que tal amigo ";
	char c = ' ';
	char **str;

	str = ft_split(s, c);
}