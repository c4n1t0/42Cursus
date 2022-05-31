/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:13:13 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/31 17:59:07 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *ptr, ...)
{
	int		i;
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
			else if (*p == 's')
				i = ft_putstr(va_arg(args, char *), i);
			else if (*p == 'c')
				i = ft_putchar(va_arg(args, int), i);
			else if (*p == '%')
				write(1, p, 1);
		}
		else
			write(1, p, 1);
		p++;
		if (*p != '\0')
			i++;
	}
	va_end(args);
	return (i);
}
