/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:02:36 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/01 21:00:56 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_mayus(unsigned long long num)
{
	if (num == 10)
		write(1, "A", 1);
	else if (num == 11)
		write(1, "B", 1);
	else if (num == 12)
		write(1, "C", 1);
	else if (num == 13)
		write(1, "D", 1);
	else if (num == 14)
		write(1, "E", 1);
	else if (num == 15)
		write(1, "F", 1);
	else if (num < 10)
	{
		num = num + '0';
		write(1, &num, 1);
	}
}

void	ft_hex_minus(unsigned long long num)
{
	if (num == 10)
		write(1, "a", 1);
	else if (num == 11)
		write(1, "b", 1);
	else if (num == 12)
		write(1, "c", 1);
	else if (num == 13)
		write(1, "d", 1);
	else if (num == 14)
		write(1, "e", 1);
	else if (num == 15)
		write(1, "f", 1);
	else if (num < 10)
	{
		num = num + '0';
		write(1, &num, 1);
	}
}

int	ft_calc_hex_mayus(unsigned long long num, int i)
{
	int	d;

	if (num < 16)
	{
		ft_hex_mayus(num);
		i++;
	}
	else if (num >= 16)
	{
		d = num % 16;
		num = num / 16;
		i = ft_calc_hex_mayus(num, i);
		ft_hex_mayus(d);
		i++;
	}
	return (i);
}

int	ft_calc_hex_minus(unsigned long long num, int i)
{
	int	d;

	if (num < 16)
	{
		ft_hex_minus(num);
		i++;
	}
	else if (num >= 16)
	{
		d = num % 16;
		num = num / 16;
		i = ft_calc_hex_minus(num, i);
		ft_hex_minus(d);
		i++;
	}
	return (i);
}

int	ft_unsigned_putnbr(unsigned int n, int i)
{
	int	d;

	if (n < 0)
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
	if ((c >= 32 && c < 127) || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\0')
		i++;
	return (i);
}
