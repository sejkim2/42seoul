/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:56 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/23 17:40:06 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//연결 리스트를 모두 해제
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*del_node;

	p = *lst;
	*lst = 0;	//head를 0으로 두어 메모리 누수를 막음
	while (p)
	{
		//삭제할 이전 노드를 임시 변수에 넣어 메모리를 해제하고
		//다음 노드로 
		del_node = p;
		p = p->next;
		del(del_node->content);
		free(del_node);
	}
}
