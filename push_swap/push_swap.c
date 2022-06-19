/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/19 13:50:35 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

int		ft_push_swap_source_validator(char **argc, int argn);
int		ft_comprob_dupl(char **argc, int count);
int		ft_comprob_dupli_loop(char **argc, int count, int i, int j);
int		ft_comprob_num(char **argc, int argn);
int		ft_comprob_int(char **argc, int argn);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(int argn, char **argc)
{
	int	i;

	if (argn < 2)
		return (0);
	i = ft_push_swap_source_validator(argc, argn);
	if (i == 0)
		ft_printf("comprobarcion OK\n");
	if (i < 0)
	{
		ft_printf("error\n");
		return (-1);
	}
	return (0);
}
