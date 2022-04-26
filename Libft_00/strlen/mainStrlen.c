/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainStrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:31:51 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/20 10:25:11 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

int	main(void)
{
	const char	*s;

	s = "asdf asdf	";
	printf("Mi funcion devuelve = %ld\n", ft_strlen(s));
	printf("La original devuelve = %ld\n", strlen(s));
	return (0);
}
