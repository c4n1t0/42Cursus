/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:29:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/08/01 18:15:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive(int signal)
{
	ft_printf("signal = %d\n", signal);
}

int	main(void)
{
	ft_printf("SERVER PID = %d\n", getpid());
	signal(SIGUSR1, ft_receive);
	while (1)
		pause();
}
