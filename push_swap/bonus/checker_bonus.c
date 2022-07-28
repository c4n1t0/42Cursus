/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/28 18:04:50 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int	checker_action(int *ptr_a, int *ptr_b, struct s_counts s)
{
	if (ft_strncmp(s.ptr, "sa\n", 4) == 0)
		ft_swap_a_sa(ptr_a);
	else if (ft_strncmp(s.ptr, "pa\n", 4) == 0)
		ft_push_a(ptr_a, ptr_b, ++*s.count_a, --*s.count_b);
	else if (ft_strncmp(s.ptr, "ra\n", 4) == 0)
		ft_rotate_a_ra(ptr_a, *s.count_a);
	else if (ft_strncmp(s.ptr, "rra\n", 5) == 0)
		ft_reverse_rotate_a_rra(ptr_a, *s.count_a);
	else if (ft_strncmp(s.ptr, "sb\n", 4) == 0)
		ft_swap_b_sb(ptr_b);
	else if (ft_strncmp(s.ptr, "pb\n", 4) == 0)
		ft_push_b(ptr_a, ptr_b, --*s.count_a, ++*s.count_b);
	else if (ft_strncmp(s.ptr, "rb\n", 4) == 0)
		ft_rotate_b_rb(ptr_b, *s.count_b);
	else if (ft_strncmp(s.ptr, "rrb\n", 5) == 0)
		ft_reverse_rotate_b_rrb(ptr_b, *s.count_b);
	else if (ft_strncmp(s.ptr, "ss\n", 4) == 0)
		ft_swap_ss(ptr_a, ptr_b);
	else if (ft_strncmp(s.ptr, "rr\n", 4) == 0)
		ft_rotate_rr(ptr_a, *s.count_a, ptr_b, *s.count_b);
	else if (ft_strncmp(s.ptr, "rrr\n", 5) == 0)
		ft_reverse_rotate_rrr(ptr_a, *s.count_a, ptr_b, *s.count_b);
	else
		return (-1);
	return (0);
}

int	checker_read(int *ptr_a, int *ptr_b, int count_a)
{
	struct s_counts	s;
	int				count_b;

	count_b = 0;
	s.count_a = &count_a;
	s.count_b = &count_b;
	s.ptr = get_next_line(0);
	checker_action(ptr_a, ptr_b, s);
	while (s.ptr)
	{
		s.ptr = get_next_line(0);
		if (s.ptr)
		{
			if (checker_action(ptr_a, ptr_b, s) == -1)
				return (ft_printf("Error\n"), -1);
		}
	}
	if (ft_swap_validator(ptr_a, count_a + 1) == 0 && *s.count_b == 0)
		ft_printf("OK\n");
	else
		return (ft_printf("KO\n"), -1);
	return (0);
}

int	ft_arg_2(char **argv, char **p, int x, int j)
{
	int	*ptr_a;
	int	*ptr_b;

	p = ft_split(argv[1], ' ');
	while (p[j])
		j++;
	if (j < 2)
		return (0);
	if (ft_push_swap_source_validator(p, j, 0) < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ptr_a = ft_resrv_stack(j + 1, p, 0);
	x = -1;
	while (p[++x])
		free(p[x]);
	free(p);
	if (ft_swap_validator(ptr_a, j + 1) == 0)
		return (free(ptr_a), 0);
	ptr_b = malloc((j + 1) * sizeof(int));
	if (checker_read(ptr_a, ptr_b, j) == -1)
		return (free(ptr_a), free(ptr_b), -1);
	return (free(ptr_a), free(ptr_b), 0);
}

int	ft_arg_more2(int argc, char **argv)
{
	//int		*ptr_a;
	//int		*ptr_b;
	char	*str;

	str = NULL;
	if (ft_push_swap_source_validator(argv, argc, 1) < 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	//ptr_a = ft_resrv_stack1(argc, argv, 1);
	//if (ft_swap_validator(ptr_a, argc) == 0)
	//	return (free(ptr_a), 0);
	//ptr_b = malloc(argc * sizeof(int));
	scanf("%s", str);
	//free(ptr_a);
	//free(ptr_b);
	return (0);
}

int	main(int argc, char **argv)
{
	// int		j;
	// char	**p;
	// int		x;

	// x = 0;
	// j = 0;
	// p = NULL;
	// if (argc < 2)
	// 	return (0);
	// if (argc == 2)
	// 	return (ft_arg_2(argv, p, x, j));
	// else if (argc > 2)
	// 	return (ft_arg_more2(argc, argv));
	(void)argc;
	(void)argv;
	char *str;

	printf("HOLA\n");
	str = get_next_line(0);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(0);
	}
}
