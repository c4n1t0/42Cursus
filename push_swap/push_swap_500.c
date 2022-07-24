/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:42:44 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/24 12:39:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_500(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	cut;
	int	mid;
	int	x;
	int	i;
	int	ref;

	ref = count_a / 11;
	i = 0;
	x = 0;
	cut = ref;
	mid = cut / 2;
	/*while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			count_a--;
			count_b++;
			ft_push_b(ptrA, ptrB, count_a, count_b);
			if (ft_look_cut_down(ptrA, count_a, cut) == -1 && ptrB[0] <= (cut - mid))
				ft_rotate_b_rb(ptrB, count_b);
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
			{
				ft_reverse_rotate_a_rra(ptrA, count_a);
				if (ptrB[0] <= (cut - mid))
					ft_rotate_b_rb(ptrB, count_b);
			}
			else
			{
				if (ptrB[0] <= (cut - mid))
					ft_rotate_rr(ptrA, count_a, ptrB, count_b);
				else
					ft_rotate_a_ra(ptrA, count_a);
			}
		}
	}*/
	while (ft_look_cut_down(ptrA, count_a, 100) > -1)
	{
		cut = cut + ref;
		while (ft_look_cut_down(ptrA, count_a, cut) > -1)
		{
			if (ptrA[0] <= cut)
			{
				ft_push_b(ptrA, ptrB, count_a, count_b);
				count_a--;
				count_b++;
				if (ptrB[0] > (cut - mid) && ptrA[0] <= cut)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				{
					ft_reverse_rotate_a_rra(ptrA, count_a);
					if (ptrB[0] > (cut - mid))
					{
						ft_rotate_b_rb(ptrB, count_b);
						i++;
					}
				}
				else
				{
					if (ptrB[0] > (cut - mid))
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
		x++;
	}

	while (ft_look_cut_down(ptrA, count_a, 200) > -1)
	{
		cut = cut + ref;
		while (ft_look_cut_down(ptrA, count_a, cut) > -1)
		{
			if (ptrA[0] <= cut)
			{
				ft_push_b(ptrA, ptrB, count_a, count_b);
				count_a--;
				count_b++;
				if (ptrB[0] > (cut - mid) && ptrA[0] <= cut)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				{
					ft_reverse_rotate_a_rra(ptrA, count_a);
					if (ptrB[0] > (cut - mid))
					{
						ft_rotate_b_rb(ptrB, count_b);
						i++;
					}
				}
				else
				{
					if (ptrB[0] > (cut - mid))
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
		x++;
	}

	while (ft_look_cut_down(ptrA, count_a, 300) > -1)
	{
		cut = cut + ref;
		while (ft_look_cut_down(ptrA, count_a, cut) > -1)
		{
			if (ptrA[0] <= cut)
			{
				ft_push_b(ptrA, ptrB, count_a, count_b);
				count_a--;
				count_b++;
				if (ptrB[0] > (cut - mid) && ptrA[0] <= cut)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				{
					ft_reverse_rotate_a_rra(ptrA, count_a);
					if (ptrB[0] > (cut - mid))
					{
						ft_rotate_b_rb(ptrB, count_b);
						i++;
					}
				}
				else
				{
					if (ptrB[0] > (cut - mid))
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
		x++;
	}

	while (ft_look_cut_down(ptrA, count_a, 400) > -1)
	{
		cut = cut + ref;
		while (ft_look_cut_down(ptrA, count_a, cut) > -1)
		{
			if (ptrA[0] <= cut)
			{
				ft_push_b(ptrA, ptrB, count_a, count_b);
				count_a--;
				count_b++;
				if (ptrB[0] > (cut - mid) && ptrA[0] <= cut)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				{
					ft_reverse_rotate_a_rra(ptrA, count_a);
					if (ptrB[0] > (cut - mid))
					{
						ft_rotate_b_rb(ptrB, count_b);
						i++;
					}
				}
				else
				{
					if (ptrB[0] > (cut - mid))
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
		x++;
	}

	while (ft_look_cut_down(ptrA, count_a, 460) > -1)
	{
		cut = cut + ref;
		while (ft_look_cut_down(ptrA, count_a, cut) > -1)
		{
			if (ptrA[0] <= cut)
			{
				ft_push_b(ptrA, ptrB, count_a, count_b);
				count_a--;
				count_b++;
				if (ptrB[0] > (cut - mid) && ptrA[0] <= cut)
				{
					ft_rotate_b_rb(ptrB, count_b);
					i++;
				}
			}
			else
			{
				if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				{
					ft_reverse_rotate_a_rra(ptrA, count_a);
					if (ptrB[0] > (cut - mid))
					{
						ft_rotate_b_rb(ptrB, count_b);
						i++;
					}
				}
				else
				{
					if (ptrB[0] > (cut - mid))
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
		x++;
	}
	//ft_part_final_ordenation(ptrA, count_a, ptrB, count_b);
	//ft_print_stack(ptrA, count_a);
	//ft_print_stack(ptrB, count_b);
	x = 0;
	while (count_a > 5)
	{
		if (ft_search_small(ptrA, count_a) > (count_a / 2))
			x = 1;
		while (ft_look_small(ptrA, count_a) != 0)
		{
			if (x == 0)
			{
				if (ft_search_small(ptrA, count_a) == 2)
					ft_swap_a_sa(ptrA);
				else
					ft_rotate_a_ra(ptrA, count_a);
			}
			else
				ft_reverse_rotate_a_rra(ptrA, count_a);
		}
		x = 0;
		ft_push_b(ptrA, ptrB, count_a, count_b);
		count_a--;
		count_b++;
	}
	ft_swap_5(ptrA, ptrB, count_a, count_b);
	ft_push_a_all(ptrA, count_a, ptrB, count_b);
}
