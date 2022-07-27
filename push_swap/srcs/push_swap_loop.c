/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:42:44 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/27 11:42:17 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sub_ini_part(int *ptrA, int *ptrB, struct s_counts s)
{
	if (ft_look_cut_down(ptrA, *s.count_a, s.cut) > ft_look_cut_up(ptrA,
			*s.count_a, s.cut))
	{
		ft_reverse_rotate_a_rra(ptrA, *s.count_a);
		if (ptrB[0] <= s.mid && *s.count_b > 1)
			ft_rotate_b_rb(ptrB, *s.count_b);
	}
	else
	{
		if (ptrB[0] <= s.mid)
			ft_rotate_rr(ptrA, *s.count_a, ptrB, *s.count_b);
		else
			ft_rotate_a_ra(ptrA, *s.count_a);
	}
}

void	ft_ini_part(int *ptrA, int *ptrB, struct s_counts s)
{
	while (ft_look_cut_down(ptrA, *s.count_a, s.cut) > -1)
	{
		if (ptrA[0] <= s.cut)
		{
			ft_push_b(ptrA, ptrB, --*s.count_a, ++*s.count_b);
			if (ft_look_cut_down(ptrA, *s.count_a, s.cut) == -1
				&& ptrB[0] <= s.mid)
				ft_rotate_b_rb(ptrB, *s.count_b);
		}
		else
			ft_sub_ini_part(ptrA, ptrB, s);
	}
}

void	ft_sub_loop_part(int *ptrA, int *ptrB, struct s_counts s)
{
	if (ft_look_cut_down(ptrA, *s.count_a, s.cut) > ft_look_cut_up(ptrA,
			*s.count_a, s.cut))
	{
		ft_reverse_rotate_a_rra(ptrA, *s.count_a);
		if (ptrB[0] > (s.cut - s.mid))
			ft_rotate_b_rb(ptrB, *s.count_b);
	}
	else
	{
		if (ptrB[0] > (s.cut - s.mid))
			ft_rotate_rr(ptrA, *s.count_a, ptrB, *s.count_b);
		else
			ft_rotate_a_ra(ptrA, *s.count_a);
	}
}

void	ft_loop_part(int *ptrA, int *ptrB, struct s_counts s)
{
	while (s.x < s.loop)
	{
		s.cut = s.cut + s.ref;
		while (ft_look_cut_down(ptrA, *s.count_a, s.cut) > -1)
		{
			if (ptrA[0] <= s.cut)
			{
				ft_push_b(ptrA, ptrB, --*s.count_a, ++*s.count_b);
				if (ptrB[0] > (s.cut - s.mid) && ptrA[0] <= s.cut)
					ft_rotate_b_rb(ptrB, *s.count_b);
			}
			else
				ft_sub_loop_part(ptrA, ptrB, s);
		}
		s.x++;
	}
}

void	ft_part_final_ordenation(int *ptrA, int *ptrB, struct s_counts s)
{
	int	x;

	x = 0;
	while (*s.count_a > 5)
	{
		if (ft_search_small(ptrA, *s.count_a) > (*s.count_a / 2))
			x = 1;
		while (ft_look_small(ptrA, *s.count_a) != 0)
		{
			if (x == 0)
			{
				if (ft_search_small(ptrA, *s.count_a) == 2)
					ft_swap_a_sa(ptrA);
				else
					ft_rotate_a_ra(ptrA, *s.count_a);
			}
			else
				ft_reverse_rotate_a_rra(ptrA, *s.count_a);
		}
		x = 0;
		ft_push_b(ptrA, ptrB, --*s.count_a, ++*s.count_b);
	}
}
