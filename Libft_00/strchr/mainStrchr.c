/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainStrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:23:32 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 00:30:22 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int	main(void)
{
	const char s[] = "hola";
	int c;

	c = 'l';

	printf("Lo que apunta s = %c\n", *ft_strchr(s, c));
	return (0);
}