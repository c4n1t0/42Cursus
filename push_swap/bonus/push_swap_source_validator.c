/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_source_validator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:12:50 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/27 11:55:18 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int	ft_comprob_int(char **argc, int argn, int start)
{
	int		i;
	int		j;
	char	*max;
	char	*min;

	max = "2147483647";
	min = "-2147483648";
	i = start;
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

int	ft_comprob_num(char **argc, int argn, int start)
{
	char	*p;
	int		i;
	int		x;

	x = 0;
	i = start;
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
		x = 0;
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

int	ft_comprob_dupl(char **argc, int count, int start)
{
	int	i;
	int	j;
	int	x;

	j = start - 1;
	i = 0;
	x = ft_comprob_dupli_loop(argc, count, i, j);
	if (x == -1)
		return (-1);
	return (0);
}

int	ft_push_swap_source_validator(char **argc, int argn, int start)
{
	if (ft_comprob_num(argc, argn, start) < 0 || ft_comprob_int(argc, argn,
			start) < 0 || ft_comprob_dupl(argc, argn, start) < 0)
		return (-1);
	return (0);
}
