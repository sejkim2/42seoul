/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:43 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/18 13:26:01 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	run_command_ra_rra_rb_rrb(t_stack *a, t_stack *b, \
t_node *min_node)
{
	while (min_node->count_ra > 0)
	{
		min_node->count_ra--;
		ra(a);
	}
	while (min_node->count_rb > 0)
	{
		min_node->count_rb--;
		rb(b);
	}
	while (min_node->count_rra > 0)
	{
		min_node->count_rra--;
		rra(a);
	}
	while (min_node->count_rrb > 0)
	{
		min_node->count_rrb--;
		rrb(b);
	}
}

static	void	run_command_rr_rrr(t_stack *a, t_stack *b, t_node *min_node)
{
	while (min_node->count_rr > 0)
	{
		min_node->count_rr--;
		rr(a, b);
	}
	while (min_node->count_rrr > 0)
	{
		min_node->count_rrr--;
		rrr(a, b);
	}
}

static	t_node	*find_min_command_node(t_stack *a, t_stack *b, int *min_num)
{
	t_node	*cur;
	t_node	*min_node;
	int		num_of_move;
	int		index;

	cur = b->top;
	min_node = cur;
	num_of_move = 0;
	index = 1;
	while (index <= b->num_of_node)
	{
		num_of_move = set_min_node(a, b, cur, index);
		if (*min_num > num_of_move)
		{
			*min_num = num_of_move;
			min_node = cur;
		}
		index++;
		cur = cur->next;
	}
	return (min_node);
}

int	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*cur;
	t_node	*min_node;
	int		min_num;

	min_num = MAX_VALUE;
	min_node = find_min_command_node(a, b, &min_num);
	run_command_rr_rrr(a, b, min_node);
	run_command_ra_rra_rb_rrb(a, b, min_node);
	pa(a, b);
	cur = b->top;
	while (cur)
	{
		init_my_node(cur);
		cur = cur->next;
	}
	set_min_node_and_max_node(a);
	return (min_num + 1);
}
