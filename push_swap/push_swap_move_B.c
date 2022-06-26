/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_B.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:00:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 13:11:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_b_sb(int *ptr)
{
	int	swap;

	swap = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = swap;
	ft_printf("sb\n");
}
//ojo push A no está completa, hay que tratar stack B

int	*ft_push_b(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	*rtp;
	int	i;
	int	j;
	int	x;

	x = count_a;
	i = x;
	i = 1;
	j = 0;
	rtp = malloc((count_b + 1) * sizeof(int));
	while (i < (count_b + 1))
	{
		rtp[i] = ptrA[j];
		i++;
		j++;
	}
	free(ptrA);
	rtp[0] = ptrB[0];
	if (count_b == 1)
		free(ptrB);
	ft_printf("pb\n");
	return (rtp);
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
	ft_printf("rb\n");
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
	ft_printf("rrb\n");
}
