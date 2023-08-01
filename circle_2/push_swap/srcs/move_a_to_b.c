/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:40 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/18 13:24:04 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	orders_are_mid_tail_top(t_stack *stack)
{
	stack->min_node = stack->top;
	sa(stack);
	ra(stack);
	return (2);
}

static	int	orders_are_mid_top_tail(t_stack *stack)
{
	stack->min_node = stack->tail;
	rra(stack);
	return (1);
}

static	int	orders_are_top_mid_tail(t_stack *stack)
{
	stack->min_node = stack->tail;
	sa(stack);
	rra(stack);
	return (2);
}

static	int	sorting_if_size_is_three(t_stack *stack, int top_value, \
int mid_value, int tail_value)
{
	if (mid_value > top_value && mid_value > tail_value)
	{
		stack->max_node = stack->top->next;
		if (top_value < tail_value)
			return (orders_are_mid_tail_top(stack));
		else
			return (orders_are_mid_top_tail(stack));
	}
	else if (top_value > mid_value && top_value > tail_value)
	{
		stack->max_node = stack->top;
		if (mid_value > tail_value)
			return (orders_are_top_mid_tail(stack));
		else
			return (orders_are_top_tail_mid(stack));
	}
	else
	{
		stack->max_node = stack->tail;
		if (mid_value < top_value)
			return (orders_are_tail_top_mid(stack));
		else
			return (orders_are_tail_mid_top(stack));
	}
}

int	move_a_to_b(t_stack *a, t_stack *b)
{
	int	count_a;
	int	count_b;

	count_a = 0;
	count_b = 0;
	while (a->num_of_node > 3)
	{
		pb(a, b);
		count_b++;
	}
	count_a = sorting_if_size_is_three(a, a->top->value, \
	a->top->next->value, a->tail->value);
	return (count_a + count_b);
}
