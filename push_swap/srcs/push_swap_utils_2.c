/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:07:08 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/21 17:46:53 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_stack(int *ptr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("%d\n", ptr[i]);
		i++;
	}
	ft_printf("\n");
}

int	ft_biggest_from_stack(int ref, int *ptr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ref < ptr[i])
			return (-1);
		i++;
	}
	return (0);
}
