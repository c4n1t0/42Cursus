/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/04 15:36:17 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_reserv(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word++;
		i++;
	}
	word++;
	printf("%d\n", word);
	return (word);
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
		if (str[i] == c)
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
	x++;
	p[x] = malloc(1 * sizeof(char));
	p[x] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**p;
	int		i;

	if (!*s)
		return (NULL);
	str = (char *)s;
	printf("%s\n", str);
	i = ft_count_reserv(str, c);
	if (!s || !(p = malloc((i + 1) * sizeof(char *))))
		return (NULL);
	return (ft_reserv(str, p, c));
}

int	main(void)
{
	char const	s[];
	char		c;
	char		**str;
	int			i;

	s[] = "hola que tal amigo";
	i = 0;
	c = 'n';
	str = ft_split(s, c);
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	printf("%s\n", str[4]);
	return (0);
}

char	**ft_words_reserv(char **p, char *str, char c, int words)
{
	int i;
	int a;
	int x;
	char *q;

	x = 0;
	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			q = malloc(i * sizeof(char));
			while (*str != c)
			{
				q[a] = *str;
				a++;
				str++;
			}
			q[a] = '\0';
			p[x] = q;
			str++;
			while (*str == c)
				str++;
			i = 0;
			a = 0;
			x++;
		}
		i++;
	}
	q = malloc(i * sizeof(char));
	while (*str != '\0')
	{
		q[a] = *str;
		a++;
		str++;
	}
	q[a] = '\0';
	p[x] = q;
	x++;
	p[x] = NULL;
	return (p);
}