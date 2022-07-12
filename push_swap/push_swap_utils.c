/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:12:35 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/12 21:58:16 by jaromero         ###   ########.fr       */
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

int	*ft_resrv_stack(int argn, char **argc, int start)
{
	int	i;
	int	j;
	int	*ptr;

	j = 0;
	i = start;
	ptr = malloc((argn - 1) * sizeof(int));
	while (i + 1 < argn)
	{
		ptr[j] = ft_atoi(argc[i]);
		i++;
		j++;
	}
	return (ptr);
}

int	*ft_resrv_stack1(int argn, char **argc, int start)
{
	int	i;
	int	j;
	int	*ptr;

	j = 0;
	i = start;
	ptr = malloc((argn - 1) * sizeof(int));
	while (i < argn)
	{
		ptr[j] = ft_atoi(argc[i]);
		i++;
		j++;
	}
	return (ptr);
}

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
