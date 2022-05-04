/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:37:34 by jaromero          #+#    #+#             */
/*   Updated: 2022/04/28 17:57:49 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == __SIZE_MAX__ && size > 0)
		return (NULL);
	if (size == __SIZE_MAX__ && nmemb > 0)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (p);
	p = malloc(nmemb * size);
	ft_bzero(p, nmemb * size);
	return (p);
}
