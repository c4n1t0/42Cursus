/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:46:18 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 12:31:50 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	signo;
	int	dev;

	signo = 1;
	dev = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signo = signo * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		dev = dev * 10 + (*nptr - '0');
		nptr++;
	}
	dev = dev * signo;
	return (dev);
}
