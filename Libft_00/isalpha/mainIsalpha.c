/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainIsalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:36:55 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 00:10:19 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c);

int	main(void)
{
	int	c;

	c = '1';
	printf("Mi funcion devuelve = %d\n", ft_isalpha(c));
	printf("La original devuelve = %d\n", isalpha(c));
	return (0);
}
