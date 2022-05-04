/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/04 16:28:04 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			if (s[i] != c)
				word++;
		}
		else
			i++;
	}
	word++;
	return (word);
}

static void	ft_reserv_word(char *str, char c, char **p)
{
	int		i;
	char	*word;
	char	*s;
	int		x;

	i = 0;
	x = 0;
	s = str;
	printf("c = %c\n", c);
	while (*str != '\0')
	{
		printf("hola%d\n", i);
		if (*s == c)
		{
			printf("		hola1\n");
			word = malloc((i + 1) * sizeof(char));
			i = 0;
			while (str != s && *str != '\0')
			{
				word[i] = *str;
				i++;
				str++;
			}
			word[i] = '\0';
			p[x] = word;
			while (*str == c)
				str++;
			printf("%s\n", str);
			s = str;
			x++;
			i = 0;
		}
		else
		{
			i++;
			s++;
			//str++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**p;
	int		words;

	if (!s)
		return (NULL);
	str = ft_strtrim(s, &c);
	printf("despues del trim -%s-\n", str);
	words = ft_count_word((char *)s, c);
	p = malloc(words * sizeof(char *));
	printf("Contador de palabras %d\n", words);
	if (!p)
		return (NULL);
	ft_reserv_word(str, c, p);
	return (p);
}

int	main(void)
{
	char const s[] = "      hola  que   tal amigo     ";
	char c;
	char **str;
	int i;

	i = 0;
	c = ' ';
	str = ft_split(s, c);
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	printf("%s\n", str[4]);
	printf("%s\n", str[5]);
	printf("%s\n", str[6]);

	return (0);
}