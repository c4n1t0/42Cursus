/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:42:44 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/26 00:48:40 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_a_all(int *ptrA, int count_a, int *ptrB, int count_b)
{
	int	x;

	x = 0;
	while (count_b > 0)
	{
		if (ft_search_big(ptrB, count_b) > (count_b / 2))
			x = 1;
		while (ft_look_big(ptrB, count_b) != 0)
		{
			if (x == 0)
			{
				if (ft_search_big(ptrB, count_b) == 2)
					ft_swap_b_sb(ptrB);
				else
					ft_rotate_b_rb(ptrB, count_b);
			}
			else
				ft_reverse_rotate_b_rrb(ptrB, count_b);
		}
		x = 0;
		ft_push_a(ptrA, ptrB, count_a++, count_b--);
	}
}

void	ft_swap_100(int *ptrA, int *ptrB, int count_a, int count_b)
{
	struct s_counts	s;
	int				i;

	if (count_a <= 20)
	{
		i = 2;
		s.loop = 0;
	}
	else
	{
		i = 5;
		s.loop = 3;
	}
	s.count_a = &count_a;
	s.count_b = &count_b;
	s.ref = *s.count_a / i;
	s.x = 0;
	s.cut = s.ref;
	s.mid = s.cut / 2;
	ft_ini_part(ptrA, ptrB, s);
	ft_loop_part(ptrA, ptrB, s);
	ft_part_final_ordenation(ptrA, ptrB, s);
	ft_swap_5(ptrA, ptrB, *s.count_a, *s.count_b);
	ft_push_a_all(ptrA, *s.count_a, ptrB, *s.count_b);
}

void	ft_swap_500(int *ptrA, int *ptrB, int count_a, int count_b)
{
	struct s_counts	s;
	int				i;

	i = 12;
	s.loop = 11;
	s.count_a = &count_a;
	s.count_b = &count_b;
	s.ref = *s.count_a / i;
	s.x = 0;
	s.cut = s.ref;
	s.mid = s.cut / 2;
	ft_loop_part(ptrA, ptrB, s);
	ft_part_final_ordenation(ptrA, ptrB, s);
	ft_swap_5(ptrA, ptrB, *s.count_a, *s.count_b);
	ft_push_a_all(ptrA, *s.count_a, ptrB, *s.count_b);
}
