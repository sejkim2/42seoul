/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_if_size_is_three_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:08 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/18 13:36:16 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	orders_are_tail_top_mid(t_stack *stack)
{
	stack->min_node = stack->top->next;
	sa(stack);
	return (1);
}

int	orders_are_tail_mid_top(t_stack *stack)
{
	stack->min_node = stack->top;
	return (0);
}

int	orders_are_top_tail_mid(t_stack *stack)
{
	stack->min_node = stack->top->next;
	ra(stack);
	return (1);
}
