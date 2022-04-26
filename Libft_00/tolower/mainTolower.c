/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTolower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:45:14 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/22 10:47:47 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c);

int	main(void)
{
	int		c;
	char	s;
	int		c1;
	char	s1;

	c = 'A';
	c1 = c;
	s1 = c1;
	s = c;
	printf("Antes de la funcion = %c\n\n", s);
	s1 = tolower(c1);
	printf("despues de la funcion original = %c\n\n", s1);
	s = ft_tolower(c);
	printf("despues de la funcion mia      = %c\n\n", s);
	return (0);
}
