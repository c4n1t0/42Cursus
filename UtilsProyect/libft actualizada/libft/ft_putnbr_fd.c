/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:54:31 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/02 19:30:09 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	d;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		if (n > 9)
		{
			d = n % 10;
			n = n / 10;
			ft_putnbr_fd(n, fd);
			ft_putchar_fd(d + '0', fd);
		}
	}
}
