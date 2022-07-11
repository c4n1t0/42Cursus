/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:10:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/11 18:50:23 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_search_small(int *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < len)
	{
		if (ptr[j] < ptr[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i + 1);
}

int	ft_search_big(int *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < len)
	{
		if (ptr[j] > ptr[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i + 1);
}

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
	while (ft_look_small(ptrA, count_a - 1) != 0)
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

void	ft_swap_100(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	y;
	int	x;

	y = count_a / 4;
	x = 0;
	while (count_a > 0)
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
	if (ft_search_small(ptrA, count_a) > (count_a / 2))
		x = 1;
	while (ft_look_small(ptrA, count_a - 1) != 0)
	{
		if (x == 0)
			ft_rotate_a_ra(ptrA, count_a);
		else
			ft_reverse_rotate_a_rra(ptrA, count_a);
	}
	while (count_b > 0)
	{
		ft_push_a(ptrA, ptrB, count_a, count_b);
		count_a++;
		count_b--;
	}
	//ft_print_stack(ptrA, count_a);
	//ft_print_stack(ptrB, count_b);
}

void	ft_renum(int *ptrA, int count_a)
{
	int	i;
	int	j;
	int	x;
	int	*aux;

	aux = malloc(count_a * sizeof(int));
	i = 0;
	x = 0;
	j = 0;
	while (i < count_a)
	{
		while (j < count_a)
		{
			if (ptrA[i] > ptrA[j])
				x++;
			j++;
		}
		aux[i] = x + 1;
		j = 0;
		x = 0;
		i++;
	}
	while (j < count_a)
	{
		ptrA[j] = aux[j];
		j++;
	}
	free(aux);
}

int	ft_look_cut_down(int *ptrA, int count_a, int cut)
{
	int	i;

	i = 0;
	while (i < count_a)
	{
		if (ptrA[i] <= cut)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_look_cut_up(int *ptrA, int count_a, int cut)
{
	int	i;

	i = count_a;
	while (i > 0)
	{
		if (ptrA[i] <= cut)
			return (count_a - i);
		i--;
	}
	return (-1);
}

void	ft_swap_100_v2(int *ptrA, int *ptrB, int count_a, int count_b)
{
	int	cut;
	int	x;

	x = 0;
	cut = 20;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				ft_reverse_rotate_a_rra(ptrA, count_a);
			else
				ft_rotate_a_ra(ptrA, count_a);
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
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				ft_reverse_rotate_a_rra(ptrA, count_a);
			else
				ft_rotate_a_ra(ptrA, count_a);
		}
	}
	cut = 60;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				ft_reverse_rotate_a_rra(ptrA, count_a);
			else
				ft_rotate_a_ra(ptrA, count_a);
		}
	}
	cut = 80;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				ft_reverse_rotate_a_rra(ptrA, count_a);
			else
				ft_rotate_a_ra(ptrA, count_a);
		}
	}
	while (count_a > 0)
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
	cut = count_a;
	while (ft_look_cut_down(ptrA, count_a, cut) > -1)
	{
		if (ptrA[0] <= cut)
		{
			ft_push_b(ptrA, ptrB, count_a, count_b);
			count_a--;
			count_b++;
		}
		else
		{
			if (ft_look_cut_down(ptrA, count_a, cut) > ft_look_cut_up(ptrA, count_a, cut))
				ft_reverse_rotate_a_rra(ptrA, count_a);
			else
				ft_rotate_a_ra(ptrA, count_a);
		}
	}
	//ft_print_stack(ptrA, count_a);
	//ft_print_stack(ptrB, count_b);
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
		//if (ptrB[0] < y)
		//{
		ft_push_a(ptrA, ptrB, count_a, count_b);
		count_a++;
		count_b--;
		//ft_swap_100(ptrA, ptrB, count_a, count_b);
		//}
	}
	
	//ft_print_stack(ptrA, count_a);
	//ft_print_stack(ptrB, count_b);
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
	else if (count_a > 5)
	{
		ft_renum(ptrA, count_a);
		ft_swap_100_v2(ptrA, ptrB, count_a, count_b);
	}
	return (0);
}
