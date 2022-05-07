/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/07 17:35:12 by jaromero         ###   ########.fr       */
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
	if (s[i] == '\0' && word == 1)
		word++;
	return (word);
}

static char	*ft_reserv_word(char const *s, int ini, int fin)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(((fin - ini) + 1) * sizeof(char));
	while (ini < fin)
	{
		word[i] = s[ini];
		i++;
		ini++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_distrb(char const *s, char c, char **p)
{
	size_t	i;
	size_t	x;
	int		o;

	i = 0;
	x = 0;
	while (s[i] == c)
		i++;
	o = i;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c) || (s[i] == '\0'))
		{
			p[x] = ft_reserv_word(s, o, i);
			x++;
			while (s[i] == c)
				i++;
			o = i;
		}
		i++;
	}
	p[x] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc((ft_count_word((char *)s, c)) * sizeof(char *));
	if (!p)
		return (NULL);
	return (ft_distrb(s, c, p));
}