/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:10:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/24 19:43:29 by jaromero         ###   ########.fr       */
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

void	ft_swap_4(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	x;

	x = 0;
	if (ft_search_small(ptrA, count_a) > (count_a / 2))
		x = 1;
	while (ft_look_small(ptrA, count_a) != 0)
	{
		if (x == 0)
			ft_rotate_a_ra(ptrA, count_a);
		else
			ft_reverse_rotate_a_rra(ptrA, count_a);
	}
	count_a--;
	count_b++;
	ft_push_b(ptrA, ptrB, count_a, count_b);
	if (ft_swap_validator(ptrA, count_a + 1) != 0)
		ft_swap_3(ptrA, count_a);
	ft_push_a(ptrA, ptrB, count_a, count_b);
	count_a++;
	count_b--;
}

void	ft_swap_5(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	x;

	x = 0;
	if (ft_search_small(ptrA, count_a) > (count_a / 2))
		x = 1;
	while (ft_look_small(ptrA, count_a) != 0)
	{
		if (x == 0)
			ft_rotate_a_ra(ptrA, count_a);
		else
			ft_reverse_rotate_a_rra(ptrA, count_a);
	}
	ft_push_b(ptrA, ptrB, count_a, count_b);
	count_a--;
	count_b++;
	ft_swap_4(ptrA, ptrB, count_a, count_b);
	ft_push_a(ptrA, ptrB, count_a, count_b);
	count_a++;
	count_b--;
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
	else if (count_a == 3)
		ft_swap_3(ptrA, count_a);
	else if (count_a == 4)
		ft_swap_4(ptrA, ptrB, count_a, count_b);
	else if (count_a == 5)
		ft_swap_5(ptrA, ptrB, count_a, count_b);
	else if (count_a > 5 && count_a < 150)
	{
		ft_renum(ptrA, count_a);
		ft_swap_100(ptrA, ptrB, count_a, count_b);
	}
	else if (count_a >= 150)
	{
		ft_renum(ptrA, count_a);
		ft_swap_500(ptrA, ptrB, count_a, count_b);
	}
	return (0);
}
