/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:06 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/21 20:03:40 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	run_push_swap(t_stack **a, t_stack **b)
{
	sorting(*a, *b);
	free_stack(*a);
	free_stack(*b);
}
