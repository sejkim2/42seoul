/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:09 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 17:57:09 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *newList;

    newList = (t_list *)malloc(sizeof(t_list));
    if (newList == 0)
        return (0);
    newList->next = 0;
    newList->content = content;

    return (newList);
}