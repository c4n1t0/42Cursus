/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/20 13:42:14 by jaromero         ###   ########.fr       */
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
	char		*buff;
	static char	buffer[BUFFER_SIZE];
	char		*str;
	char		*p;
	int			i;
	char		*ptr;
	int			j;

	i = 0;
	if (!buff)
		buff = str;
	//if (*buff != '\0')
	//	str = ft_strjoin(str, buff);
	while (*buff != '\n')
	{
		if (*buff != '\0')
		{
			//write(1, buff, 1);
			buff++;
			i++;
		}
		if (ft_strlen(buff) < 1 || *buff == '\0')
		{
			buff = buffer;
			ft_read_fd(fd, buff);
			str = ft_strjoin(str, buff);
			//p = ft_strchr(str, '\n');
		}
	}
	//printf("str = \n%s\n", str);
	if (*buff == '\n')
		i++;
	p = ft_calloc((i + 1), sizeof(char));
	//printf("str = \n%s\n", str);
	//ptr = ft_save(str, p, i);
	j = 0;
	//printf("contador %d\n", i);
	while (i > 0)
	{
		p[j] = str[j];
		if (str[j] != '\0')
			j++;
		i--;
	}
	//str[j] = '\n';
	if (ft_strlen(buff) > 1)
	{
		free(str);
		str = ft_strjoin(str, buff);
	}
	else
		free(str);
	buff++;
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
	while (count < 10)
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