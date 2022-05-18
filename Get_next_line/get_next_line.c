/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/17 14:00:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	static int	d;
	static char	buffer[BUFFER_SIZE];
	ssize_t		rd;
	int			count;

	d = 0;
	count = 0;
	buff = buffer;
	printf("buff esta apuntando a: %s\n", buff);
	//if (*buff == '\0')
	rd = read(fd, buffer, BUFFER_SIZE);
	//write(1, "rd del read: &rd\n", 15);
	d = 1;
	if (!buff)
		return (NULL);
	while (*buff != '\n' && count < rd)
	{
		write(1, buff, 1);
		buff++;
		count++;
	}
	/*if (*buff == '\n')
	{
		write(1, "\n", 1);
		//count++;
	}*/
	return (buff);
}

int	main(void)
{
	int		fd1;
	char	*ptrbuff;
	int		count;

	count = 0;
	fd1 = 0;
	fd1 = open("./numbers.dict", O_RDONLY);
	while (count < 10)
	{
		ptrbuff = get_next_line(fd1);
		count++;
	}
	close(fd1);
	return (0);
}
