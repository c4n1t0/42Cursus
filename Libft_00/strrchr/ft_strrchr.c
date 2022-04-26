/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:51:55 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 00:58:12 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 1;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	if (*s == c)
		return (s);
	while (count > 0)
	{
		if (*s == c)
			return (s);
		else
		{
			s--;
			count--;
		}
	}
	return ('\0');
}
