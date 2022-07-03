/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:10:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/04 00:05:09 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_3(int *ptr, int len)
{
	if (ft_look_big(ptr, len) == 0)
	{
		ft_rotate_a_ra(ptr, len);
		if (ft_look_small(ptr, len) == 0)
			return ;
		else
			ft_swap_a_sa(ptr);
		return ;
	}
	else if (ft_look_small(ptr, len) == 0)
	{
		ft_rotate_a_ra(ptr, len);
		ft_swap_a_sa(ptr);
		ft_reverse_rotate_a_rra(ptr, len);
		return ;
	}
	else
	{
		ft_reverse_rotate_a_rra(ptr, len);
		if (ft_swap_validator(ptr, len) == -1)
		{
			ft_rotate_a_ra(ptr, len);
			ft_swap_a_sa(ptr);
		}
	}
}

void	ft_swap_5(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	i;

	i = 0;
	ft_push_b(ptrA, ptrB, count_a, count_b);
	count_a--;
	count_b++;
	ft_push_b(ptrA, ptrB, count_a, count_b);
	count_a--;
	count_b++;
	if (ft_swap_validator(ptrA, count_a) != 0)
		ft_swap_3(ptrA, count_a);
	/*while (ft_swap_validator(ptrA, count_a + 1) != 0)
	{
		if (ptrA[0] < ptrA[1])
			ft_rotate_a_ra(ptrA, count_a);
		else if (ptrA[0] > ptrA[1] && ptrA[0] < ptrA[2])
			ft_swap_a_sa(ptrA);
		else if (ptrA[0] > ptrA[1] && ptrA[0] > ptrA[2])
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
		}
	}*/
	ft_print_stack(ptrA, count_a);
	ft_print_stack(ptrB, count_b);
	while (ft_swap_validator(ptrA, count_a) != 0 || count_b != 0)
	{
		if (ptrA[0] < ptrB[0] && ft_look_big(ptrA, count_a) == 0 && count_b > 0)
		{
			ft_push_a(ptrA, ptrB, count_a, count_b);
			count_a++;
			count_b--;
		}
		else if (ptrA[0] < ptrB[0] && ft_look_big(ptrA, count_a) != 0)
		{
			ft_rotate_a_ra(ptrA, count_a);
			if (ptrA[0] > ptrB[0] && count_b > 0)
			{
				ft_push_a(ptrA, ptrB, count_a, count_b);
				count_a++;
				count_b--;
			}
		}
		else if (ptrB[0] > ptrA[0] && ptrB[0] < ptrA[1])
		{
			ft_rotate_a_ra(ptrA, count_a);
			ft_push_a(ptrA, ptrB, count_a, count_b);
			count_a++;
			count_b--;
		}
		else if (ptrB[0] < ptrA[0] && ft_look_small(ptrA, count_a) == 0
				&& count_b > 0)
		{
			ft_push_a(ptrA, ptrB, count_a, count_b);
			count_a++;
			count_b--;
		}
		else if (ptrB[0] < ptrA[0] && count_b > 0)
			ft_reverse_rotate_a_rra(ptrA, count_a);
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
