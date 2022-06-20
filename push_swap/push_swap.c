/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/20 22:10:46 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
//#include "libft.h"

int		ft_push_swap_source_validator(char **argc, int argn);
int		ft_comprob_dupl(char **argc, int count);
int		ft_comprob_dupli_loop(char **argc, int count, int i, int j);
int		ft_comprob_num(char **argc, int argn);
int		ft_comprob_int(char **argc, int argn);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);

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
	free(ptr);
	return (0);
}
