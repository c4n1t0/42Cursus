/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:07:18 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/16 00:37:24 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_design(char *nm, int i, char *p)
{
	int	o;

	o = 0;
	while (i >= 0)
	{
		if (*nm == '-')
		{
			p[o] = *nm;
			o++;
		}
		else
		{
			p[o] = nm[i];
			o++;
			i--;
		}
	}
	o++;
	return (p);
}

static int	ft_conv(char *nm, int n)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	if (n < 0)
	{
		n = n * -1;
		a = 1;
	}
	while (n > 9)
	{
		nm[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	nm[i] = n + '0';
	i++;
	if (a == 1)
	{
		nm[i] = '-';
		i++;
	}
	nm[i] = '\0';
	return (i);
}

char	*ft_itoa(int n)
{
	char	nm[12];
	char	*p;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		ft_strlcpy(nm, "8463847412-", 12);
		i = 11;
	}
	else
		i = ft_conv(nm, n);
	p = ft_calloc(i + 1, sizeof(char));
	if (!p)
		return (NULL);
	i--;
	return (ft_design(nm, i, p));
}
