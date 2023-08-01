/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_ra_rb_rr_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 17:18:04 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static	void	run_ra(t_stack *a)
{
	t_node	*move_to_tail;

	if (a->num_of_node > 1)
	{
		move_to_tail = a->top;
		a->top = a->top->next;
		a->top->prev = 0;
		a->tail->next = move_to_tail;
		move_to_tail->prev = a->tail;
		move_to_tail->next = 0;
		a->tail = move_to_tail;
	}
}

static	void	run_rb(t_stack *b)
{
	t_node	*move_to_tail;

	if (b->num_of_node > 1)
	{
		move_to_tail = b->top;
		b->top = b->top->next;
		b->top->prev = 0;
		b->tail->next = move_to_tail;
		move_to_tail->prev = b->tail;
		move_to_tail->next = 0;
		b->tail = move_to_tail;
	}
}

void	ra(t_stack *a)
{
	run_ra(a);
}

void	rb(t_stack *b)
{
	run_rb(b);
}

void	rr(t_stack *a, t_stack *b)
{
	run_ra(a);
	run_rb(b);
}
