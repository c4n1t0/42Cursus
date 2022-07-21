/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:42:44 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/21 18:55:55 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_100(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	cut;
	int	x;
	int	i;

	i = 0;
	x = 0;
	cut = 20;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			count_a--;
			count_b++;
			ft_push_b(ptrA, ptrB, count_a, count_b);
			if (ft_look_cut_down(ptrA, count_a, cut) == -1 && ptrB[0] <= 10)
				ft_rotate_b_rb(ptrB, count_b);
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA,
					count_a, cut))
			{
				ft_reverse_rotate_a_rra(ptrA, count_a);
				if (ptrB[0] <= 10)
					ft_rotate_b_rb(ptrB, count_b);
			}
			else
			{
				if (ptrB[0] <= 10)
					ft_rotate_rr(ptrA, count_a, ptrB, count_b);
				else
					ft_rotate_a_ra(ptrA, count_a);
			}
		}
	}
	cut = 40;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
			if (ptrB[0] > 30 && ptrA[0] <= cut)
			{
				ft_rotate_b_rb(ptrB, count_b);
				i++;
			}
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA,
					count_a, cut))
			{
				ft_reverse_rotate_a_rra(ptrA, count_a);
				if (ptrB[0] > 30)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ptrB[0] > 30)
				{
					ft_rotate_rr(ptrA, count_a, ptrB, count_b);
					i++;
				}
				else
					ft_rotate_a_ra(ptrA, count_a);
			}
		}
	}
	while (i > 0)
	{
		ft_reverse_rotate_b_rrb(ptrB, count_b);
		i--;
	}
	cut = 60;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
			if (ptrB[0] > 50 && ptrA[0] <= cut)
			{
				ft_rotate_b_rb(ptrB, count_b);
				i++;
			}
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA,
					count_a, cut))
			{
				ft_reverse_rotate_a_rra(ptrA, count_a);
				if (ptrB[0] > 50)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ptrB[0] > 50)
				{
					ft_rotate_rr(ptrA, count_a, ptrB, count_b);
					i++;
				}
				else
					ft_rotate_a_ra(ptrA, count_a);
			}
		}
	}
	while (i > 0)
	{
		ft_reverse_rotate_b_rrb(ptrB, count_b);
		i--;
	}
	cut = 80;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
			if (ptrB[0] > 70 && ptrA[0] <= cut)
			{
				ft_rotate_b_rb(ptrB, count_b);
				i++;
			}
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA,
					count_a, cut))
			{
				ft_reverse_rotate_a_rra(ptrA, count_a);
				if (ptrB[0] > 70)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ptrB[0] > 70)
				{
					ft_rotate_rr(ptrA, count_a, ptrB, count_b);
					i++;
				}
				else
					ft_rotate_a_ra(ptrA, count_a);
			}
		}
	}
	while (i > 0)
	{
		ft_reverse_rotate_b_rrb(ptrB, count_b);
		i--;
	}
	while (count_a > 5)
	{
		if (ft_search_small(ptrA, count_a) > (count_a / 2))
			x = 1;
		while (ft_look_small(ptrA, count_a) != 0)
		{
			if (x == 0)
				ft_rotate_a_ra(ptrA, count_a);
			else
				ft_reverse_rotate_a_rra(ptrA, count_a);
		}
		x = 0;
		ft_push_b(ptrA, ptrB, count_a, count_b);
		count_a--;
		count_b++;
	}
	ft_swap_5(ptrA, ptrB, count_a, count_b);
	while (count_b > 0)
	{
		if (ft_search_big(ptrB, count_b) > (count_b / 2))
			x = 1;
		while (ft_look_big(ptrB, count_b) != 0)
		{
			if (x == 0)
				ft_rotate_b_rb(ptrB, count_b);
			else
				ft_reverse_rotate_b_rrb(ptrB, count_b);
		}
		x = 0;
		ft_push_a(ptrA, ptrB, count_a, count_b);
		count_a++;
		count_b--;
	}
}
