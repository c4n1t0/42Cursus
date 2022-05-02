/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/02 23:22:44 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_count_reserv(char *str, char c)
{
	int		i;
	int		word;
	char	**p;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word++;
		i++;
	}
	word++;
	p = (char **)malloc(sizeof(char) * word);
	return (p);
}

char	**ft_reserv(char *str, char **p, char c)
{
	unsigned int	i;
	unsigned int	x;
	char			*q;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
		{
			q = &str[i] + 1;
			str[i] = '\0';
			p[x] = malloc((ft_strlen(str) + 1) * sizeof(char));
			ft_strlcpy(p[x], str, ft_strlen(str) + 1);
			str = q;
			i = 0;
			x++;
		}
		i++;
	}
	p[x] = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_strlcpy(p[x], str, ft_strlen(str) + 1);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**p;

	str = ft_strtrim(s, &c);
	p = ft_count_reserv(str, c);
	return (ft_reserv(str, p, c));
}

int	main(void)
{
	char const s[] = " hola que tal amigo ";
	char c;
	char **str;

	c = ' ';
	str = ft_split(s, c);
	printf("%s\n", str[3]);
}