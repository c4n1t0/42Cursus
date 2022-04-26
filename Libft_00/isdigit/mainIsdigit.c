/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainIsdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:13:29 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 00:09:27 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c);

int	main(void)
{
	int	c;

	c = 'j';
	printf("Mi funcion devuelve = %d\n", ft_isdigit(c));
	printf("La original devuelve = %d\n", isdigit(c));
	return (0);
}
