/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainIsascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:54:29 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 00:09:01 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c);

int	main(void)
{
	int	c;

	c = '\n';
	printf("Mi funcion devuelve = %d\n", ft_isascii(c));
	printf("La original devuelve = %d\n", isascii(c));
	return (0);
}
