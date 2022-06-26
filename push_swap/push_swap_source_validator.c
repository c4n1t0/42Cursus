/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_source_validator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:12:50 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/23 21:31:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_comprob_int(char **argc, int argn)
{
	int		i;
	int		j;
	char	*max;
	char	*min;

	max = "2147483647";
	min = "-2147483648";
	i = 1;
	while (i < argn)
	{
		if (ft_strlen(argc[i]) >= 10)
		{
			j = ft_strncmp(argc[i], max, 11);
			if (j > 0)
				return (-1);
		}
		if (ft_strlen(argc[i]) >= 11)
		{
			j = ft_strncmp(argc[i], min, 11);
			if (j > 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_comprob_num(char **argc, int argn)
{
	char	*p;
	int		i;
	int		x;

	x = 0;
	i = 1;
	p = argc[i];
	while (i < argn)
	{
		while (*p != '\0')
		{
			if ((*p == '-' && x == 0) || (*p == '+' && x == 0))
			{
				p++;
				x = 1;
			}
			if (*p < 48 || *p > 57)
				return (-1);
			p++;
		}
		i++;
		p = argc[i];
	}
	return (0);
}

int	ft_comprob_dupli_loop(char **argc, int count, int i, int j)
{
	char	*p;
	char	*q;

	while (j < (count - 1))
	{
		i = ++j + 1;
		q = argc[i];
		p = argc[j];
		while (i < count)
		{
			if (*p == *q)
			{
				while (*p == *q && p && q)
				{
					if (*p == '\0' && *q == '\0')
						return (-1);
					p++;
					q++;
				}
				p = argc[j];
			}
			q = argc[++i];
		}
	}
	return (0);
}

int	ft_comprob_dupl(char **argc, int count)
{
	int	i;
	int	j;
	int	x;

	j = 0;
	i = 0;
	x = ft_comprob_dupli_loop(argc, count, i, j);
	if (x == -1)
		return (-1);
	return (0);
}

int	ft_push_swap_source_validator(char **argc, int argn)
{
	int	i;

	i = ft_comprob_num(argc, argn);
	if (i < 0)
		return (-1);
	i = ft_comprob_int(argc, argn);
	if (i < 0)
		return (-1);
	i = ft_comprob_dupl(argc, argn);
	if (i < 0)
		return (-1);
	return (0);
}
