/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:06 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/24 19:54:24 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	run_push_swap(t_stack **a, t_stack **b)
{
	int	is_sorted;

	is_sorted = sorting(*a, *b);
	free_stack(*a);
	free_stack(*b);
	if (is_sorted == 0)
		ft_printf("KO\n");
	else if (is_sorted == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		ft_printf("OK\n");
}
