/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_and_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:01 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/21 13:14:43 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	b_node_value_is_min(t_stack *a, t_node *b_node)
{
	t_node	*cur;

	cur = a->top;
	while (cur != a->min_node)
	{
		b_node->count_ra++;
		cur = cur->next;
	}
}

static	void	b_node_value_is_max(t_stack *a, t_node *b_node)
{
	t_node	*cur;

	cur = a->top;
	while (cur != a->max_node)
	{
		b_node->count_ra++;
		cur = cur->next;
	}
	if (cur != 0)
	{
		b_node->count_ra++;
		cur = cur->next;
	}
}

static	void	push_while_b_is_bigger_than_a(t_stack *a, t_node *b_node)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->value < b_node->value)
	{
		b_node->count_ra++;
		cur = cur->next;
	}
}

static	void	push_while_b_is_smaller_than_a(t_stack *a, t_node *b_node)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->value > b_node->value)
	{
		b_node->count_ra++;
		cur = cur->next;
	}
	while (cur && cur->value < b_node->value)
	{
		b_node->count_ra++;
		cur = cur->next;
	}
}

int	rrb_and_ra(t_stack *a, t_stack *b, t_node *b_node, int index)
{
	b_node->count_rrb = b->num_of_node - index + 1;
	if (b_node->value < a->top->value && b_node->value > a->tail->value)
		return (b_node->count_rrb);
	if (b_node->value < a->min_node->value)
		b_node_value_is_min(a, b_node);
	else if (b_node->value > a->max_node->value)
		b_node_value_is_max(a, b_node);
	else if (a->top->value < b_node->value)
		push_while_b_is_bigger_than_a(a, b_node);
	else
		push_while_b_is_smaller_than_a(a, b_node);
	return (b_node->count_ra + b_node->count_rrb);
}
