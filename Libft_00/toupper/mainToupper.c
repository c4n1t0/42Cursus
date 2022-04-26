/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainToupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:24:32 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/22 10:42:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_toupper(int c);

int	main(void)
{
	int		c;
	char	s;
	int		c1;
	char	s1;

	c = 'w';
	c1 = c;
	s1 = c1;
	s = c;
	printf("Antes de la funcion = %c\n\n", s);
	s1 = toupper(c1);
	printf("despues de la funcion original = %c\n\n", s1);
	s = ft_toupper(c);
	printf("despues de la funcion mia      = %c\n\n", s);
	return (0);
}
