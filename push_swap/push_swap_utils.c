/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:12:35 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 17:49:57 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_swap_validator(int *ptr, int len)
{
	int	i;

	i = 0;
	while (i < (len - 2))
	{
		if (ptr[i] > ptr[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	*ft_resrv_stack(int argn, char **argc)
{
	int	i;
	int	j;
	int	*ptr;

	j = 0;
	i = 1;
	ptr = malloc((argn - 1) * sizeof(int));
	while (i < argn)
	{
		ptr[j] = ft_atoi(argc[i]);
		i++;
		j++;
	}
	return (ptr);
}
