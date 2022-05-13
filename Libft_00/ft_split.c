/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/13 16:56:13 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *s, char c, int len)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (len >= 0)
	{
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				i++;
			if (s[i] != c || s[i] == '\0')
			{
				word++;
				if (s[i] == '\0')
				{
					word++;
					return (word);
				}
			}
		}
		len--;
		i++;
	}
	return (word);
}

static char	*ft_reserv_word(char const *s, int ini, int fin)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(((fin - ini) + 1) * sizeof(char));
	if (!word)
		return (NULL);
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
	unsigned long int	i;
	int					x;
	int					o;

	i = 0;
	x = 0;
	while (s[i] == c)
		i++;
	o = i;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c || (i == ft_strlen(s) && i - o >= 1))
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
	int		word;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	word = ft_count_word((char *)s, c, len);
	p = (char **)malloc(word * sizeof(char *));
	if (!p)
		return (NULL);
	return (ft_distrb(s, c, p));
}
