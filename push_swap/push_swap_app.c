/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:10:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/04 16:38:23 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_3(int *ptr, int len)
{
	if (ptr[0] > ptr[1] && ptr[1] > ptr[2])
	{
		ft_rotate_a_ra(ptr, len);
		ft_swap_a_sa(ptr);
	}
	else if (ptr[0] > ptr[1] && ptr[0] > ptr[2])
		ft_rotate_a_ra(ptr, len);
	else if (ptr[0] < ptr[1] && ptr[0] > ptr[2])
		ft_reverse_rotate_a_rra(ptr, len);
	else if (ptr[0] > ptr[1] && ptr[0] < ptr[2])
		ft_swap_a_sa(ptr);
	else if (ptr[0] < ptr[1] && ptr[0] < ptr[2])
	{
		ft_reverse_rotate_a_rra(ptr, len);
		ft_swap_a_sa(ptr);
	}
}

void	ft_swap_5(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	i;

	i = 0;
	/*while (ft_look_big(ptrA, count_a) != 0)
		ft_rotate_a_ra(ptrA, count_a);*/
	ft_push_b(ptrA, ptrB, count_a, count_b);
	count_a--;
	count_b++;
	/*while (ft_look_big(ptrA, count_a) != 0)
		ft_rotate_a_ra(ptrA, count_a);*/
	ft_push_b(ptrA, ptrB, count_a, count_b);
	count_a--;
	count_b++;
	if (ft_swap_validator(ptrA, count_a + 1) != 0)
		ft_swap_3(ptrA, count_a);
	if (ptrB[0] < ptrB[1])
		ft_swap_b_sb(ptrB);
	while (count_b > 0)
	{
		if (ptrA[4] < ptrB[0] && ptrA[1] > ptrB[0])
		{
			ft_push_a(ptrA, ptrB, count_a, count_b);
			count_a++;
			count_b--;
		}
		else if (ptrA[0] < ptrB[0] && ft_look_small(ptrA, count_a) == 0)
		{
			ft_push_a(ptrA, ptrB, count_a, count_b);
			count_a++;
			count_b--;
		}
		else
			ft_rotate_a_ra(ptrA, count_a);
	}
	ft_print_stack(ptrA, count_a);
	ft_print_stack(ptrB, count_b);
}

int	ft_push_swap(int *ptrA, int *ptrB, int count_a)
{
	int	count_b;

	count_b = 0;
	if (count_a == 2)
	{
		ft_rotate_a_ra(ptrA, count_a);
		return (0);
	}
	if (count_a == 3)
		ft_swap_3(ptrA, count_a);
	if (count_a > 3) // && count_a < 6
	{
		ft_swap_5(ptrA, ptrB, count_a, count_b);
	}
	return (0);
}
