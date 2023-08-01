/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_sa_sb_ss_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:13:39 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 18:51:17 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static	void	run_sa(t_stack *a)
{
	int	tmp;

	if (a->num_of_node > 1)
	{
		tmp = a->top->value;
		a->top->value = a->top->next->value;
		a->top->next->value = tmp;
	}
}

static	void	run_sb(t_stack *b)
{
	int	tmp;

	if (b->num_of_node > 1)
	{
		tmp = b->top->value;
		b->top->value = b->top->next->value;
		b->top->next->value = tmp;
	}
}

void	sa(t_stack *a)
{
	run_sa(a);
}

void	sb(t_stack *b)
{
	run_sb(b);
}

void	ss(t_stack *a, t_stack *b)
{
	run_sa(a);
	run_sb(b);
}
