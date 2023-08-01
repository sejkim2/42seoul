/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:11 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/18 17:01:56 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_my_node(t_node *node)
{
	node->count_rr = 0;
	node->count_rrr = 0;
	node->count_ra = 0;
	node->count_rb = 0;
	node->count_rra = 0;
	node->count_rrb = 0;
}

void	set_min_node_and_max_node(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	if (stack->max_node == 0 && stack->min_node == 0)
	{
		stack->max_node = stack->top;
		stack->min_node = stack->top;
	}
	while (cur)
	{
		if (cur->value > stack->max_node->value)
			stack->max_node = cur;
		if (cur->value < stack->min_node->value)
			stack->min_node = cur;
		cur = cur->next;
	}
}

static	int	*set_arr(t_stack *a, t_stack *b, t_node *b_node, int index)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 4);
	arr[0] = rb_and_ra(a, b_node, index);
	init_my_node(b_node);
	arr[1] = rrb_and_ra(a, b, b_node, index);
	init_my_node(b_node);
	arr[2] = rb_and_rra(a, b_node, index);
	init_my_node(b_node);
	arr[3] = rrb_and_rra(a, b, b_node, index);
	init_my_node(b_node);
	return (arr);
}

static	int	set_min_value_and_return_min_index(int *arr)
{
	int	i;
	int	min_value;
	int	min_index;

	i = 0;
	min_value = MAX_VALUE;
	min_index = 0;
	while (i < 4)
	{
		if (min_value > arr[i])
		{
			min_value = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	set_min_node(t_stack *a, t_stack *b, t_node *b_node, int index)
{
	int	*arr;
	int	min_index;

	arr = set_arr(a, b, b_node, index);
	min_index = set_min_value_and_return_min_index(arr);
	free(arr);
	if (min_index == 0)
		return (rb_and_ra(a, b_node, index));
	else if (min_index == 1)
		return (rrb_and_ra(a, b, b_node, index));
	else if (min_index == 2)
		return (rb_and_rra(a, b_node, index));
	else
		return (rrb_and_rra(a, b, b_node, index));
}
