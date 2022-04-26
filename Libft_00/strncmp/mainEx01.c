/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainEx01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:12:01 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 01:45:19 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, size_t n);

int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	n;
	int		x;

	n = 6;
	s1 = "test/200";
	s2 = "test/0";
	printf("\nla cadena s1 = %s\n\n", s1);
	printf("la cadena s2 = %s\n\n", s2);
	x = ft_strncmp(s1, s2, n);
	if (x > 0)
		printf("la cadena de entrada es mayor %d\n", x);
	else if (x == 0)
		printf("las cadenas son de iguales %d\n", x);
	else if (x < 0)
		printf("La cadena de entrada es menor %d\n\n", x);
	return (0);
}
