/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_B_silent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:00:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/27 11:54:55 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_swap_b_sb(int *ptr)
{
	int	swap;

	swap = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = swap;
}

void	ft_push_b(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	i;
	int	j;
	int	*rtp;

	rtp = malloc((count_b + 1) * sizeof(int));
	rtp[0] = ptrA[0];
	i = 0;
	j = 0;
	while (i < count_b)
	{
		rtp[i + 1] = ptrB[i];
		i++;
	}
	while (j <= count_b)
	{
		ptrB[j] = rtp[j];
		j++;
	}
	free(rtp);
	j = -1;
	while (j++ < count_a)
		ptrA[j] = ptrA[j + 1];
}

void	ft_rotate_b_rb(int *ptr, int count_b)
{
	int	rotate;
	int	i;
	int	j;

	rotate = ptr[0];
	i = 1;
	j = 0;
	while (i < count_b)
	{
		ptr[j] = ptr[i];
		j++;
		i++;
	}
	ptr[j] = rotate;
}

void	ft_reverse_rotate_b_rrb(int *ptr, int count_b)
{
	int	rotate;
	int	i;
	int	j;

	rotate = ptr[count_b - 1];
	i = count_b;
	j = count_b - 1;
	while (i > 0)
	{
		ptr[i] = ptr[j];
		j--;
		i--;
	}
	ptr[i] = rotate;
}
