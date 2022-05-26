/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/26 23:46:35 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char		*buff;
	char		buffer[BUFFER_SIZE];
	static char	*str;
	char		*ptr;
	size_t		lp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!str)
	{
		lp = read(fd, buffer, BUFFER_SIZE);
		//printf("buff = %s\n", buffer);
		str = ft_calloc(sizeof(char), (lp + 1));
		while (lp > 0)
		{
			str[i] = buffer[i];
			lp--;
			i++;
		}
		buff = ft_strchr(str, '\n');
		//printf("str = %s\n", str);
		//printf("buff = %s\n", buff);
	}
	while (!ft_strchr(str, '\n'))
	{
		lp = read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer);
		printf("str = %s\n", str);
	}
	i = 0;
	buff = str;
	while (str[i] != '\n')
		i++;
	i++;
	ptr = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (i > 0)
	{
		ptr[j] = str[j];
		i--;
		j++;
	}
	printf("ptr = %s\n", ptr);
	printf("buff = %s\n", buff);
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
		//printf("%s", ptrbuff);
		count++;
	}
	close(fd1);
	return (0);
}