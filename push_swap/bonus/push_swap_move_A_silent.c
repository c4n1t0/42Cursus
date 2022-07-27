/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_A_silent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:00:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/27 11:54:47 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_swap_a_sa(int *ptr)
{
	int	swap;

	swap = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = swap;
}

void	ft_push_a(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	i;
	int	j;
	int	*rtp;

	rtp = malloc((count_a + 1) * sizeof(int));
	rtp[0] = ptrB[0];
	i = 0;
	j = 0;
	while (i < count_a)
	{
		rtp[i + 1] = ptrA[i];
		i++;
	}
	while (j <= count_a)
	{
		ptrA[j] = rtp[j];
		j++;
	}
	free(rtp);
	j = -1;
	while (j++ < count_b)
		ptrB[j] = ptrB[j + 1];
}

void	ft_rotate_a_ra(int *ptr, int count_a)
{
	int	rotate;
	int	i;
	int	j;

	rotate = ptr[0];
	i = 1;
	j = 0;
	while (i < count_a)
	{
		ptr[j] = ptr[i];
		j++;
		i++;
	}
	ptr[j] = rotate;
}

void	ft_reverse_rotate_a_rra(int *ptr, int count_a)
{
	int	rotate;
	int	i;
	int	j;

	rotate = ptr[count_a - 1];
	i = count_a;
	j = count_a - 1;
	while (i > 0)
	{
		ptr[i] = ptr[j];
		j--;
		i--;
	}
	ptr[i] = rotate;
}
