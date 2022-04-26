/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainIsprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:18:48 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 00:28:57 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
	int	c;

	c = '\n';
	printf("Mi funcion devuelve = %d\n", ft_isprint(c));
	printf("La original devuelve = %d\n", isprint(c));
	return (0);
}
