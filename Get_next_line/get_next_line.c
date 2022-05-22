/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/22 21:44:49 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_save(char *str, char *p, int i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		p[j] = str[j];
		j++;
		i--;
	}
	p[j] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	static char	buffer[BUFFER_SIZE];
	char		*str;
	char		*p;
	int			i;
	int			j;

	i = 0;
	if (!buff)
		buff = buffer;
	while (*buff != '\n')
	{
		if (*buff != '\0')
		{
			buff++;
			i++;
		}
		if (ft_strlen(buff) < 1 || *buff == '\0')
		{
			buff = buffer;
			ft_read_fd(fd, buff);
			str = ft_strjoin(str, buff);
		}
	}
	if (*buff == '\n')
		i++;
	buff++;
	p = ft_calloc((i + 1), sizeof(char));
	j = 0;
	while (i > 0)
	{
		p[j] = str[j];
		if (str[j] != '\0')
			j++;
		i--;
	}
	free(str);
	str = ft_strjoin(str, buff);
	return (p);
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