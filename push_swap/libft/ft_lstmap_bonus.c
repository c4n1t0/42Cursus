/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:19:56 by jaromero          #+#    #+#             */
/*   Updated: 2022/05/13 13:46:18 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == 0)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (new == 0)
		return (0);
	temp = new;
	while (lst->next)
	{
		temp->next = ft_lstnew(f(lst->next->content));
		if (!temp->next)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (new);
}
