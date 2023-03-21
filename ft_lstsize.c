/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:11 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 17:57:12 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list *p;
    int count;

    if (lst == 0)
        return (0);
    p = lst;
    count = 1;
    while (p->next)
    {
        count++;
        p = p->next;
    }
    return (count);
}