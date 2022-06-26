/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:10:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 17:25:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_look_big(int *ptr, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (ptr[0] < ptr[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_look_small(int *ptr, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (ptr[0] > ptr[i])
			return (-1);
		i++;
	}
	return (0);
}

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

int	ft_push_swap(int *ptr, int len)
{
	if (len == 2)
	{
		ft_rotate_a_ra(ptr, len);
		return (0);
	}
	if (len == 3)
		ft_swap_3(ptr, len);
	return (0);
}
