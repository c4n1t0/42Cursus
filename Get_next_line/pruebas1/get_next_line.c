/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/25 14:41:03 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_read_fd(int fd, char *buff)
{
	ssize_t	rd;

	rd = read(fd, buff, BUFFER_SIZE);
	if (!rd)
		return (NULL);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		buffer[BUFFER_SIZE];
	static char	*str;
	char		*ptr;

	//buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str)
		buff = ft_strchr(str, '\n');
	while (!str)
	{
		buff = ft_read_fd(fd, buffer);
		if (!buff)
			return (NULL);
		str = ft_strjoin(str, buff);
		buff = ft_strchr(str, '\n');
	}
	//printf("ptr= %s\n", ptr);
	printf("buff= %s\n", buff);
	printf("str= %s-\n", str);
	return (0);
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
		printf("%s", ptrbuff);
		count++;
	}
	close(fd1);
	return (0);
}