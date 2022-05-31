/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:02:36 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/31 17:58:45 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int i)
{
	int	d;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (i + 11);
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			write(1, "-", 1);
			i++;
		}
		else if (n < 10)
		{
			n = n + '0';
			write(1, &n, 1);
			i++;
		}
		else if (n > 9)
		{
			d = n % 10;
			n = n / 10;
			i = ft_putnbr(n, i);
			d = d + '0';
			write(1, &d, 1);
			i++;
		}
	}
	return (i);
}

int	ft_putstr(char *s, int j)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		j++;
	}
	return (j);
}

int	ft_putchar(char c, int i)
{
	write(1, &c, 1);
	i++;
	return (i);
}
