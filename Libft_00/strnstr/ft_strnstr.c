/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:58:15 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/25 11:27:56 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	const char	*p;
	int			count;

	count = 0;
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
			p = s1;
		{
			while (*s1 != '\0' && *s2 != '\0' && len > 0)
			{
				s1++;
				s2++;
				count++;
				len--;
			}
			if (len == 0)
				return (p);
			s1 = p;
			s2 = s2 - count;
			count = 0;
		}
		s1++;
	}
	return (s1);
}
