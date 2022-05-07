/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainIsalnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:22:40 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/05 14:41:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c);

int	main(void)
{
	int	c;

	c = -1;
	printf("Mi funcion devuelve = %d\n", ft_isalnum(c));
	printf("La original devuelve = %d\n", isalnum(c));
	return (0);
}
