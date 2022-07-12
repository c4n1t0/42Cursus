/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/12 23:15:41 by jaromero         ###   ########.fr       */
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
	int		x;

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
		/*while (p[x])
		{
			ft_printf("%s\n", p[x]);
			x++;
		}*/
		if (ft_push_swap_source_validator(p, j, 0) < 0)
		{
			ft_printf("Error\n");
			system("leaks -q push_swap");
			return (-1);
		}
		ptrA = ft_resrv_stack(j + 1, p, 0);
		ptrB = malloc((j + 1) * sizeof(int));
		/*x = -1;
		while (q[++x])
			free(q[x]);
		free(q);*/
		x = -1;
		while (p[++x])
			free(p[x]);
		free(p);
		if (ft_swap_validator(ptrA, j + 1) == 0)
			return (0);
		ft_push_swap(ptrA, ptrB, j);
		//ft_print_stack(ptrA, j);
		free(ptrA);
		free(ptrB);
	}
	else if (argc > 2)
	{
		if (ft_push_swap_source_validator(argv, argc, 1) < 0)
		{
			ft_printf("Error\n");
			return (-1);
		}
		ptrA = ft_resrv_stack1(argc, argv, 1);
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
