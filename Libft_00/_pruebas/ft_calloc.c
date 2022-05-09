/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:37:34 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/09 12:21:47 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = NULL;
	if (nmemb == __SIZE_MAX__ && size > 1)
		return (NULL);
	if (size == __SIZE_MAX__ && nmemb > 1)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (p);
	p = malloc(nmemb * size);
	ft_bzero(p, nmemb * size);
	return (p);
}
