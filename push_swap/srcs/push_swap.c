/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/08/02 12:36:24 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_arg_2(char **argv, char **p, int x, int j)
{
	int	*ptr_a;
	int	*ptr_b;

	p = ft_split(argv[1], ' ');
	while (p[j])
		j++;
	if (ft_push_swap_source_validator(p, j, 0) < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (j < 2)
		return (0);
	ptr_a = ft_resrv_stack(j + 1, p, 0);
	x = -1;
	while (p[++x])
		free(p[x]);
	free(p);
	if (ft_swap_validator(ptr_a, j + 1) == 0)
		return (free(ptr_a), 0);
	ptr_b = malloc((j + 1) * sizeof(int));
	ft_push_swap(ptr_a, ptr_b, j);
	free(ptr_a);
	free(ptr_b);
	return (0);
}

int	ft_arg_more2(int argc, char **argv)
{
	int	*ptr_a;
	int	*ptr_b;

	if (ft_push_swap_source_validator(argv, argc, 1) < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ptr_a = ft_resrv_stack1(argc, argv, 1);
	if (ft_swap_validator(ptr_a, argc) == 0)
		return (free(ptr_a), 0);
	ptr_b = malloc(argc * sizeof(int));
	ft_push_swap(ptr_a, ptr_b, (argc - 1));
	free(ptr_a);
	free(ptr_b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		j;
	char	**p;
	int		x;

	x = 0;
	j = 0;
	p = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		j = ft_arg_2(argv, p, x, j);
		return (j);
	}
	else if (argc > 2)
	{
		j = ft_arg_more2(argc, argv);
		return (j);
	}
}
