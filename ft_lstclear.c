/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:56 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 17:56:57 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *p;

    p = *lst;
    lst = 0;
    while (p->next)
    {
        t_list *del_node;
        
        del_node = p;
        p = p->next;
        ft_lstdelone(del_node, del);
    }
    ft_lstdelone(p, del);
}