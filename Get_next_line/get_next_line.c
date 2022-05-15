/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/15 21:19:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*buff;
	char	buffer[700];
	ssize_t	rd;
	int		count;

	count = 4;
	buff = buffer;
	rd = read(fd, buff, BUFFER_SIZE);
	//	if (fd < 0 || BUFFER_SIZE <= 0)
	//		return (NULL);
	//	rd = read(fd, buff, BUFFER_SIZE);
	while (*buff != '\0' && count > 0)
	{
		if (*buff == '\n')
			count--;
		write(1, buff, 1);
		buff++;
	}
	return (buff);
}

int	main(int ac, char **av)
{
	int		fd1;
	char	*ptrbuff;
	int		count;

	count = 4;
	fd1 = 0;
	fd1 = open("./numbers.dict", O_RDONLY);
	if (fd1 == -1)
		write(1, "Error open file\n", 16);
	else
		ptrbuff = get_next_line(fd1);
	if (!ptrbuff)
		write(1, "Empty file\n", 11);
	else
		/*while (*ptrbuff != '\0' && count > 0)
		{
			if (*ptrbuff == '\n')
				count--;
			write(1, ptrbuff, 1);
			ptrbuff++;
		}*/
		close(fd1);
	return (0);
}
