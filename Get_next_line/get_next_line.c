/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/29 20:00:00 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_free_static(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

char	*ft_save(char *str, int fd)
{
	char	*buffer;
	ssize_t	lp;

	lp = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && lp > 0)
	{
		lp = read(fd, buffer, BUFFER_SIZE);
		if (lp == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[lp] = '\0';
		str = ft_free_static(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_rsv(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = 0;
	if (*str == 0)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	ptr = ft_calloc(sizeof(char), (i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		ptr[j] = str[j];
		i--;
		j++;
	}
	return (ptr);
}

char	*ft_save_rest(char *str)
{
	char	*buff;
	char	*temp;

	buff = ft_strchr(str, '\n');
	if (!buff)
	{
		free(str);
		return (NULL);
	}
	buff++;
	if (*buff == '\0')
	{
		free(str);
		return (NULL);
	}
	temp = ft_calloc(1, 1);
	temp = ft_strjoin(temp, buff);
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_calloc(1, 1);
	str = ft_save(str, fd);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ptr = ft_rsv(str);
	str = ft_save_rest(str);
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