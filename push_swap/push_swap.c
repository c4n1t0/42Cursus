/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:22:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/16 18:12:44 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

int	ft_comprob(char **argc, int count)
{
	char	*p;
	char	*q;
	int		i;
	int		j;

	j = 1;
	i = 1;
	p = argc[i];
	q = argc[i + 1];
	while (j != count)
	{
		while (i != count)
		{
			if (*p == *q)
			{
				while (*p == *q)
				{
					if (*p == '\0' && *q == '\0')
						return (-1);
					p++;
					q++;
				}
			}
			ft_printf("hola\n");
			i++;
			q = argc[i + 1];
		}
		i = 1;
		j++;
		q = argc[j + 1];
		p = argc[j];
	}
	return (0);
}

int	main(int argn, char **argc)
{
	int	i;

	if (argn < 2)
		ft_printf("error\n");
	i = ft_comprob(argc, argn);
	if (i == -1)
		ft_printf("error\n");
	return (0);
}
