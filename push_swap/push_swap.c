/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/11 22:20:35 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		*ptrA;
	int		*ptrB;
	char	**p;
	char	**q;
	int x;

	x = 0;
	j = 0;
	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		p = ft_split(argv[1], ' ');
		while (p[j])
			j++;
		if (j < 2)
			return (0);
		q = calloc(j + 2, sizeof(char));
		while (i < j)
		{
			q[i + 1] = p[i];
			i++;
		}
		while (p[x])
		{
			ft_printf("%s\n", q[x]);
			x++;
		}
		free(p);
		ft_printf("j = %d\n", j); // hasta aqui llega
		if (ft_push_swap_source_validator(q, j + 1) < 0)
		{
			ft_printf("Error\n");
			return (-1);
		}
		ptrA = ft_resrv_stack(j + 1, q);
		ptrB = malloc((j + 1) * sizeof(int));
		free(q);
		if (ft_swap_validator(ptrA, j + 1) == 0)
			return (0);
		ft_push_swap(ptrA, ptrB, j);
		//ft_print_stack(ptrA, j);
		free(ptrA);
		free(ptrB);
	}
	else if (argc > 2)
	{
		if (ft_push_swap_source_validator(argv, argc) < 0)
		{
			ft_printf("Error\n");
			return (-1);
		}
		ptrA = ft_resrv_stack(argc, argv);
		ptrB = malloc(argc * sizeof(int));
		if (ft_swap_validator(ptrA, argc) == 0)
			return (0);
		ft_push_swap(ptrA, ptrB, (argc - 1));
		//ft_print_stack(ptrA, (argc - 1));
		free(ptrA);
		free(ptrB);
	}
	//ft_print_stack(ptrA, (argc - 1));
	//free(ptrA);
	//free(ptrB);
	//system("leaks -q push_swap");
	return (0);
}
