/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:54 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 17:06:11 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	run_rra(t_stack *a)
{
	t_node	*move_to_top;

	if (a->num_of_node > 1)
	{
		move_to_top = a->tail;
		a->tail = a->tail->prev;
		a->tail->next = 0;
		a->top->prev = move_to_top;
		move_to_top->next = a->top;
		move_to_top->prev = 0;
		a->top = move_to_top;
	}
}

static	void	run_rrb(t_stack *b)
{
	t_node	*move_to_top;

	if (b->num_of_node > 1)
	{
		move_to_top = b->tail;
		b->tail = b->tail->prev;
		b->tail->next = 0;
		b->top->prev = move_to_top;
		move_to_top->next = b->top;
		move_to_top->prev = 0;
		b->top = move_to_top;
	}
}

void	rra(t_stack *a)
{
	run_rra(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	run_rrb(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	run_rra(a);
	run_rrb(b);
	ft_printf("rrr\n");
}
