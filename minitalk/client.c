/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:37:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/08/02 10:30:58 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int			pid;
	const char	*str;

	str = argv[1];
	if (argc != 3)
		return (write(1, "Error\n", 6), -1);
	pid = ft_atoi(str);
	ft_printf("pid = %d\n", pid);
}
