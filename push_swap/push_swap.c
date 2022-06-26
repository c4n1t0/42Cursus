/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 14:21:38 by jaromero         ###   ########.fr       */
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

int	main(int argn, char **argc)
{
	int	i;
	int	*ptr;

	if (argn <= 2)
		return (0);
	i = ft_push_swap_source_validator(argc, argn);
	if (i < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ptr = ft_resrv_stack(argn, argc);
	if (ft_swap_validator(ptr, argn) == 0)
		return (0);
	ft_push_swap(ptr, (argn - 1));
	ft_print_stack(ptr, (argn - 1));
	free(ptr);
	return (0);
}
