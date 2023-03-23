/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:06 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/22 17:25:45 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	t_list	*head;
	t_list	*tail;

	p = lst;
	head = 0;
	tail = head;
	while (p)
	{
		new = ft_lstnew(f(p->content));
		if (new == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		if (tail == 0)
			head = new;
		else
			tail->next = new;
		tail = new;
		p = p->next;
	}
	return (head);
}
