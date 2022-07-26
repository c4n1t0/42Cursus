/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/27 00:44:01 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	checker_action(int *ptr_a, int *ptr_b, struct s_counts s)
{
	if (ft_strncmp(s.ptr, "sa\n", 4))
		ft_swap_a_sa(ptr_a);
	/*if (ft_strncmp(s.ptr, "pa\n", 4))
	{
		ft_push_a(ptr_a, ptr_b, *s.count_a, *s.count_b);
		*s.count_a = *s.count_a + 1;
		*s.count_b = *s.count_b - 1;
	}*/
	if (ft_strncmp(s.ptr, "ra\n", 4))
		ft_rotate_a_ra(ptr_a, *s.count_a);
	if (ft_strncmp(s.ptr, "rra\n", 5))
		ft_reverse_rotate_a_rra(ptr_a, *s.count_a);
	if (ft_strncmp(s.ptr, "sb\n", 4))
		ft_swap_b_sb(ptr_b);
	if (ft_strncmp(s.ptr, "pb\n", 4))
	{
		*s.count_a = *s.count_a - 1;
		*s.count_b = *s.count_b + 1;
		ft_push_b(ptr_a, ptr_b, *s.count_a, *s.count_b);
	}
	if (ft_strncmp(s.ptr, "rb\n", 4))
		ft_rotate_b_rb(ptr_b, *s.count_b);
	if (ft_strncmp(s.ptr, "rrb\n", 5))
		ft_reverse_rotate_b_rrb(ptr_b, *s.count_b);
}

static void	checker_read(int *ptr_a, int *ptr_b, int count_a)
{
	struct s_counts	s;
	int				count_b;

	count_b = 0;
	s.count_a = &count_a;
	s.count_b = &count_b;
	ft_print_stack(ptr_a, *s.count_a);
	while (s.ptr)
	{
		s.ptr = get_next_line(0);
		ft_printf("%s\n", s.ptr);
		if (s.ptr)
			checker_action(ptr_a, ptr_b, s);
		ft_printf("count j =%d\n", *s.count_a);
	}
	ft_printf("count_a =%d\n", *s.count_a);
	ft_print_stack(ptr_a, *s.count_a);
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
	checker_read(ptr_a, ptr_b, j);
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
		return (ft_arg_2(argv, p, x, j));
}
