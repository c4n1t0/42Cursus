/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimales.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:45:32 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 17:34:18 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hex_mayus(unsigned int num)
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

void	ft_hex_minus(unsigned int num)
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

int	ft_calc_hex(unsigned int num, int i, char *p)
{
	int	d;

	if (num < 16)
	{
		if (*p == 'x')
			ft_hex_minus(num);
		else if (*p == 'X')
			ft_hex_mayus(num);
		i++;
	}
	else if (num >= 16)
	{
		d = num % 16;
		num = num / 16;
		i = ft_calc_hex(num, i, p);
		if (*p == 'x')
			ft_hex_minus(d);
		else if (*p == 'X')
			ft_hex_mayus(d);
		i++;
	}
	return (i);
}

int	ft_calc_hex_void(unsigned long long num, int i)
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
		i = ft_calc_hex_void(num, i);
		ft_hex_minus(d);
		i++;
	}
	return (i);
}
