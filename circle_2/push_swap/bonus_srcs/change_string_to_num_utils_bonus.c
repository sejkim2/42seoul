/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_string_to_num_utils_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:45 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 16:12:30 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	check_memory_error_in_change_string_to_num(long long *num_arr)
{
	if (num_arr == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
