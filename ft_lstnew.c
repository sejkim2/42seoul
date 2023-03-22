/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:09 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/22 17:26:00 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	newList = (t_list *)malloc(sizeof(t_list));
	if (new_list == 0)
		return (0);
	new_list->next = 0;
	new_list->content = content;
	return (new_list);
}
