/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:15 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/21 19:55:45 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_node	*init_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->prev = 0;
	new_node->next = 0;
	new_node->value = data;
	new_node->count_rr = 0;
	new_node->count_rrr = 0;
	new_node->count_ra = 0;
	new_node->count_rb = 0;
	new_node->count_rra = 0;
	new_node->count_rrb = 0;
	return (new_node);
}

static	t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == 0)
		return (0);
	new_stack->top = 0;
	new_stack->tail = 0;
	new_stack->max_node = 0;
	new_stack->min_node = 0;
	new_stack->num_of_node = 0;
	return (new_stack);
}

static	int	push_tail(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (new_node == 0)
		return (0);
	if (stack->num_of_node == 0)
		stack->top = new_node;
	else
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
	}
	stack->tail = new_node;
	stack->num_of_node++;
	return (1);
}

t_stack	*free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*del_node;

	cur = stack->top;
	stack->top = 0;
	stack->tail = 0;
	stack->max_node = 0;
	stack->min_node = 0;
	while (cur)
	{
		del_node = cur;
		cur = cur->next;
		free(del_node);
	}
	if (stack != 0)
		free(stack);
	return (0);
}

t_stack	*make_stack(char stack_name, int size_arr, long long *num_arr)
{
	t_stack	*new_stack;
	int		i;

	new_stack = init_stack();
	if (new_stack == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	if (stack_name == 'a')
	{
		while (i < size_arr)
		{
			if (push_tail(new_stack, num_arr[i++]) == 0)
				return (free_stack(new_stack));
		}
	}
	return (new_stack);
}
