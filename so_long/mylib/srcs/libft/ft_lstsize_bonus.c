/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:11 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:44:32 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		count;

	p = lst;
	count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return (count);
}
