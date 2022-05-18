/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/18 13:25:19 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char		*buff;
	static char	buffer[BUFFER_SIZE];
	ssize_t		rd;

	if (!buff)
		buff = buffer;
	while (*buff != '\n')
	{
		if (*buff == '\0')
		{
			rd = read(fd, buffer, BUFFER_SIZE);
			if (!rd)
				return (NULL);
			buff = buffer;
		}
		write(1, buff, 1);
		buff++;
		if (ft_strlen(buff) < 1)
		{
			rd = read(fd, buffer, BUFFER_SIZE);
			if (!rd)
				return (NULL);
			buff = buffer;
		}
	}
	if (*buff == '\n')
		write(1, "\n", 1);
	buff++;
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
	while (count < 5)
	{
		ptrbuff = get_next_line(fd1);
		if (!ptrbuff)
			return (0);
		count++;
	}
	close(fd1);
	return (0);
}
