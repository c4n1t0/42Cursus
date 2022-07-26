/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 08:41:08 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/21 09:00:10 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_search_small(int *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < len)
	{
		if (ptr[j] < ptr[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i + 1);
}

int	ft_search_big(int *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < len)
	{
		if (ptr[j] > ptr[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i + 1);
}

void	ft_renum(int *ptrA, int count_a)
{
	int	i;
	int	j;
	int	x;
	int	*aux;

	aux = malloc(count_a * sizeof(int));
	i = 0;
	while (i < count_a)
	{
		j = 0;
		x = 0;
		while (j < count_a)
		{
			if (ptrA[i] > ptrA[j])
				x++;
			j++;
		}
		aux[i] = x + 1;
		i++;
	}
	j = -1;
	while (++j < count_a)
		ptrA[j] = aux[j];
	free(aux);
}

int	ft_look_cut_down(int *ptrA, int count_a, int cut)
{
	int	i;

	i = 0;
	while (i < count_a)
	{
		if (ptrA[i] <= cut)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_look_cut_up(int *ptrA, int count_a, int cut)
{
	int	i;

	i = count_a;
	while (i > 0)
	{
		if (ptrA[i] <= cut)
			return (count_a - i);
		i--;
	}
	return (-1);
}
