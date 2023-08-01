/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:13 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/18 17:30:58 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	sorting_if_size_is_two(t_stack *a)
{
	sa(a);
	return (1);
}

static	int	move_remain(t_stack *a, int count_remain)
{
	if (count_remain < a->num_of_node / 2)
	{
		count_remain = 0;
		while (a->top != a->min_node)
		{
			ra(a);
			count_remain++;
		}
	}
	else
	{
		count_remain = 0;
		while (a->top != a->min_node)
		{
			rra(a);
			count_remain++;
		}
	}
	return (count_remain);
}

int	sorting(t_stack *a, t_stack *b)
{
	int		count_a_to_b;
	int		count_b_to_a;
	int		count_remain;
	t_node	*cur;

	if (a->num_of_node == 2)
		return (sorting_if_size_is_two(a));
	count_a_to_b = move_a_to_b(a, b);
	count_b_to_a = 0;
	count_remain = 0;
	set_min_node_and_max_node(a);
	while (b->num_of_node > 0)
		count_b_to_a += move_b_to_a(a, b);
	cur = a->top;
	while (cur->value != a->min_node->value)
	{
		count_remain++;
		cur = cur->next;
	}
	count_remain = move_remain(a, count_remain);
	return (count_a_to_b + count_b_to_a + count_remain);
}
