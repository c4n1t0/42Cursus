/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:37:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/08/01 18:19:43 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv)
{
	int	pid;

	if (argc != 3)
		return (write(1, "Error\n", 6), -1);
	pid = ft_atoi(argv[1]);
	ft_printf("pid = %d\n", pid);
}
