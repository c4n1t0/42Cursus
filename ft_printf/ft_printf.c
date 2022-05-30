/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:13:13 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/30 17:00:18 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf(char const *ptr, ...)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		write(1, &ptr[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	int	i;

	i = 5;
	i = ft_printf("hola %d\n", i);
}
