/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_pa_pb_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:48 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 17:17:13 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*push_node;

	if (b->num_of_node != 0)
	{
		push_node = b->top;
		b->top = b->top->next;
		if (b->num_of_node > 1)
			b->top->prev = 0;
		else
			b->tail = 0;
		b->num_of_node--;
		push_node->next = a->top;
		if (a->num_of_node == 0)
			a->tail = push_node;
		else
			a->top->prev = push_node;
		a->top = push_node;
		a->num_of_node++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*push_node;

	if (a->num_of_node != 0)
	{
		push_node = a->top;
		a->top = a->top->next;
		if (a->num_of_node > 1)
			a->top->prev = 0;
		else
			a->tail = 0;
		a->num_of_node--;
		push_node->next = b->top;
		if (b->num_of_node == 0)
			b->tail = push_node;
		else
			b->top->prev = push_node;
		b->top = push_node;
		b->num_of_node++;
	}
}
