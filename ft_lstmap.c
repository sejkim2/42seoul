/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:06 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 17:57:07 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *p;
    t_list *new;
    t_list *head;

    p = lst;
    while (p->next)
    {
        f(p->content);
        new = ft_lstnew(p->content);
        if (new == 0)
        {
            ft_lstclear(&head, del);
            return (0);
        }
        ft_lstadd_back(&head, new);
        p = p->next;
    }
    f(p->content);
    new = ft_lstnew(p->content);
    if (new == 0)
    {
        ft_lstclear(&head, del);
        return (0);
    }
    ft_lstadd_back(&head, new);

    return (head);
}