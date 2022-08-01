/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/12 12:07:12 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_distrib(char *tmp, unsigned int len, int word)
{
	char			**aux;
	unsigned int	i;
	unsigned int	j;

	aux = (char **)malloc(sizeof(char *) * (word + 1));
	if (aux == 0)
		return (0);
	i = 0;
	j = 0;
	if (tmp[i] != '\0')
	{
		aux[j] = ft_strdup(&tmp[i]);
		j++;
	}
	i++;
	while (i < len)
	{
		if (tmp[i] != '\0' && tmp[i - 1] == '\0')
		{
			aux[j++] = ft_strdup(&tmp[i]);
		}
		i++;
	}
	aux[j] = 0;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	int				word;
	char			*tmp;
	char			**aux;

	len = ft_strlen(s);
	tmp = ft_strdup(s);
	if (tmp == 0)
		return (0);
	word = 0;
	i = 0;
	while (i < len)
	{
		if (tmp[i] == c)
			tmp[i] = '\0';
		else if (i == 0 || tmp[i - 1] == '\0')
			word++;
		i++;
	}
	aux = ft_distrib(tmp, len, word);
	free(tmp);
	return (aux);
}
