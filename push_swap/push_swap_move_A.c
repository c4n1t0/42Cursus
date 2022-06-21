/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_A.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:00:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/21 23:52:08 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_a_SA(int *ptr)
{
	int	swap;

	swap = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = swap;
	ft_printf("sa\n");
}
//ojo push A no está completa, hay que tratar stack B
int	*ft_push_A(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	*rtp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	rtp = malloc((count_a + 1) * sizeof(int));
	while (i < (count_a + 1))
	{
		rtp[i] = ptrA[j];
		i++;
		j++;
	}
	free(ptrA);
	rtp[0] = ptrB[0];
	if (count_b == 1)
		free(ptrB);
	ft_printf("pa\n");
	return (rtp);
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
	ft_printf("ra\n");
}

void	ft_reverse_rotate_a_rra(int *ptr, int count_a)
{
	int rotate;
	int i;
	int j;

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
	ft_printf("rra\n");
}