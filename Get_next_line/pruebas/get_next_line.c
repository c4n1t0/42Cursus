/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/27 17:50:42 by jaromero         ###   ########.fr       */
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
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (!str)
		str = ft_calloc(1, 1);
	while (!ft_strchr(str, '\n') && lp != 0)
	{
		lp = read(fd, buffer, BUFFER_SIZE);
		if (lp == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[lp] = '\0';
		// printf("lp = %zu\n", lp);
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		ptr[j] = str[j];
		i--;
		j++;
	}
	buff = ft_strchr(str, '\n');
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

/*int	main(void)
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
}*/