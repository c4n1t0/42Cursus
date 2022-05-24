/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/24 17:58:49 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	char		buffer[BUFFER_SIZE];
	char		*str;
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!ft_strchr(str, '\n'))
	{
		buff = ft_read_fd(fd, buffer);
		if (!buff)
			return (NULL);
		str = ft_strjoin(str, buff);
	}
	while (str[i] != '\n')
		i++;
	i++;
	while (*buff != '\n')
		buff++;
	buff++;
	ptr = ft_calloc((i + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (i > 0)
	{
		ptr[j] = str[j];
		j++;
		i--;
	}
	free(str);
	str = ft_strjoin(str, buff);
	//printf("ptr= %s\n", ptr);
	//printf("buff= %s\n", buff);
	//printf("str= %s-\n", str);
	return (ptr);
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