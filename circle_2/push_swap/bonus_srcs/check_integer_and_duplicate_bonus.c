/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integer_and_duplicate_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:36 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 16:12:34 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static	int	check_if_number_is_integer(long long *num_arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (num_arr[i] > MAX_VALUE || num_arr[i] < MIN_VALUE)
			return (0);
		i++;
	}
	return (1);
}

static	int	check_if_num_is_duplicated(long long *num_arr, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (num_arr[i] == num_arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_integer_and_duplicate(long long *num_arr, int word_count)
{
	if (check_if_number_is_integer(num_arr, word_count) == 0)
	{
		write(2, "Error\n", 6);
		free(num_arr);
		exit(1);
	}
	if (check_if_num_is_duplicated(num_arr, word_count) == 1)
	{
		write(2, "Error\n", 6);
		free(num_arr);
		exit(1);
	}
}
