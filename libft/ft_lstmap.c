/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:03:02 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/19 15:55:25 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = (*f)(new);
	lst = lst->next;
	begin_list = new;
	while (lst)
	{
		if (!(new->next = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new->next = (*f)(new->next);
		lst = lst->next;
		new = new->next;
	}
	new->next = NULL;
	return (begin_list);
}
