/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 20:35:40 by jaromero         ###   ########.fr       */
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
	int	*ptrA;
	int	*ptrB;

	if (argn <= 2)
		return (0);
	i = ft_push_swap_source_validator(argc, argn);
	if (i < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ptrA = ft_resrv_stack(argn, argc);
	ptrB = malloc(argn * sizeof(int));
	if (ft_swap_validator(ptrA, argn) == 0)
		return (0);
	//ft_print_stack(ptrA, (argn - 1));
	ft_push_swap(ptrA, ptrB, (argn - 1));
	ft_print_stack(ptrA, (argn - 1));
	free(ptrA);
	free(ptrB);
	//system("leaks -q push_swap");
	return (0);
}
