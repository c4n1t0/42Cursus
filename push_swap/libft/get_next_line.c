/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:45:16 by jaromero          #+#    #+#             */
/*   Updated: 2022/07/26 19:22:52 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_static(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

char	*ft_save(char *str, int fd, int BUFFER_SIZE)
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
	int		i;

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
	temp = ft_calloc(sizeof(char), (ft_strlen(buff) + 1));
	i = 0;
	while (buff[i] != '\0')
	{
		temp[i] = buff[i];
		i++;
	}
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;
	int			buffer_size;

	buffer_size = 5;
	if (fd < 0 || buffer_size <= 0)
		return (NULL);
	if (!str)
		str = ft_calloc(1, 1);
	str = ft_save(str, fd, buffer_size);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ptr = ft_rsv(str);
	str = ft_save_rest(str);
	return (ptr);
}
