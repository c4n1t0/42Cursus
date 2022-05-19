/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/19 13:15:37 by jaromero         ###   ########.fr       */
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
	char		*str;
	char		*p;
	int			i;

	i = 0;
	if (!buff)
		buff = buffer;
	while (*buff != '\n')
	{
		if (*buff != '\0')
		{
			p[i] = *buff;
			buff++;
			i++;
		}
		if (ft_strlen(buff) < 1 || *buff == '\0')
		{
			buff = buffer;
			ft_read_fd(fd, buff);
			//str = ft_strjoin(str, buff);
			//p = ft_strchr(str, '\n');
		}
	}
	p[i] = *buff;
	i++;
	p[i] = '\0';
	printf("p = %s-hasta aqui \n", p);
	buff++;
	return (str);
}

int	main(void)
{
	int fd1;
	char *ptrbuff;
	int count;

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