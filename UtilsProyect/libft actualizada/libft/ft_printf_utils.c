/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:02:36 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 21:35:44 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_putnbr(unsigned int n, int i)
{
	int	d;

	if ((int)n < 0)
		n = 2 ^ 32 + n;
	if (n < 10)
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
	return (i);
}

int	ft_num_neg(int n)
{
	n = n * -1;
	write(1, "-", 1);
	return (n);
}

int	ft_putnbr(int n, int i)
{
	int	d;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11), (i + 11));
	else
	{
		if (n < 0)
		{
			n = ft_num_neg(n);
			i++;
		}
		if (n < 10)
		{
			n = n + '0';
			write(1, &n, 1);
			i++;
		}
		else if (n > 9)
		{
			d = n % 10 + '0';
			i = (ft_putnbr((n = n / 10), i)) + 1;
			write(1, &d, 1);
		}
	}
	return (i);
}

int	ft_putstr(char *s, int j)
{
	unsigned int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		j++;
	}
	return (j);
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
