/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_tweece_silent.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:20:12 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/27 11:55:11 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_swap_ss(int *ptr_a, int *ptr_b)
{
	ft_swap_tweece(ptr_a);
	ft_swap_tweece(ptr_b);
}

void	ft_rotate_rr(int *ptr_a, int count_a, int *ptr_b, int count_b)
{
	ft_rotate_tweece(ptr_a, count_a);
	ft_rotate_tweece(ptr_b, count_b);
}

void	ft_reverse_rotate_rrr(int *ptr_a, int count_a, int *ptr_b, int count_b)
{
	ft_reverse_rotate_tweece(ptr_a, count_a);
	ft_reverse_rotate_tweece(ptr_b, count_b);
}
