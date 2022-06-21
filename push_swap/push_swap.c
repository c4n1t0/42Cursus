/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/21 23:50:25 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	ft_print_stack(int *ptr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("%d\n", ptr[i]);
		i++;
	}
}

int	main(int argn, char **argc)
{
	int	i;
	int	*ptr;

	if (argn < 2)
		return (0);
	i = ft_push_swap_source_validator(argc, argn);
	if (i == 0)
		ft_printf("comprobarcion OK\n");
	if (i < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ptr = ft_resrv_stack(argn, argc);
	ft_print_stack(ptr, (argn - 1));
	ft_printf("\n");
	ft_swap_a_SA(ptr);
	ft_print_stack(ptr, (argn - 1));
	ft_printf("\n");
	ft_rotate_a_ra(ptr, (argn - 1));
	ft_print_stack(ptr, (argn - 1));
	ft_printf("\n");
	ft_reverse_rotate_a_rra(ptr, (argn - 1));
	ft_print_stack(ptr, (argn - 1));
	ft_printf("\n");
	free(ptr);
	return (0);
}
