/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/27 19:17:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char		*buff;
	char		*buffer;
	static char	*str;
	char		*ptr;
	ssize_t		lp;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	j = 0;
	i = 0;
	lp = 1;
	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && lp != 0)
	{
		lp = read(fd, buffer, BUFFER_SIZE);
		if (lp == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[lp] = '\0';
		// printf("lp = %zu\n", lp);
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	//if (lp == 0)
	//	return (free(str), NULL);
	if (!str)
		return (NULL);
	i = 0;
	// contamos longitud
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	// reservamos ptr para devolver
	ptr = ft_calloc(sizeof(char), (i + 1));
	if (!ptr)
		return (NULL);
	// copiamos en ptr
	//printf("str = %s\n", str);
	j = 0;
	while (i > 0)
	{
		ptr[j] = str[j];
		i--;
		j++;
	}
	/*if (ptr[j] == '\n')
		ptr[j + 1] = '\0';
	else
		ptr[j + 1] = '\0';*/
	// reservo en str static lo que queda dentro
	buff = ft_strchr(str, '\n');
	if (!buff)
	{
		free(str);
		return (NULL);
	}
	buff++;
	//free(str);
	str = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	while (buff[i] != '\0')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
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
	while (count < 50)
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