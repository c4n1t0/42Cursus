/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:13:13 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/02 21:56:19 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *ptr, ...)
{
	int		i;
	int		x;
	char	*p;
	va_list	args;

	p = (char *)ptr;
	i = 0;
	va_start(args, (char *)ptr);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'd' || *p == 'i')
				i = ft_putnbr(va_arg(args, int), i);
			else if (*p == 'u')
				i = ft_unsigned_putnbr(va_arg(args, unsigned int), i);
			else if (*p == 's')
				i = ft_putstr(va_arg(args, char *), i);
			else if (*p == 'c')
				i = ft_putchar(va_arg(args, int), i);
			else if (*p == 'x')
			{
				x = 0;
				i = ft_calc_hex(va_arg(args, unsigned int), i, x);
			}
			else if (*p == 'X')
			{
				x = 1;
				i = ft_calc_hex(va_arg(args, unsigned int), i, x);
			}
			else if (*p == 'p')
			{
				write(1, "0x", 2);
				i = ft_calc_hex_void(va_arg(args, unsigned long long), i) + 2;
			}
			else if (*p == '%')
			{
				write(1, p, 1);
				i++;
			}
		}
		else
		{
			write(1, p, 1);
			if ((*p >= 32 && *p < 127) || *p == '\n' || *p == '\t' || *p == '\v'
				|| *p == '\f' || *p == '\r')
				i++;
		}
		p++;
	}
	va_end(args);
	return (i);
}
