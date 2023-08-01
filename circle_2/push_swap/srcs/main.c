/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:36 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/24 12:16:03 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	is_sorted(long long *num_arr, int arr_size)
{
	int	i;

	i = 1;
	while (i < arr_size)
	{
		if (num_arr[i - 1] > num_arr[i])
			return (0);
		i++;
	}
	return (1);
}

static	void	check_if_arr_is_sorted(long long *num_arr, int arr_size)
{
	if (is_sorted(num_arr, arr_size) == 1)
	{
		free(num_arr);
		exit(0);
	}
}

static	void	make_stack_a_and_b(t_stack **a, t_stack **b, int word_count, \
long long *num_arr)
{
	*a = make_stack('a', word_count, num_arr);
	if (*a == 0)
	{
		write(2, "Error\n", 6);
		free(num_arr);
		exit(1);
	}
	*b = make_stack('b', 0, 0);
	if (*b == 0)
	{
		write(2, "Error\n", 6);
		free_stack(*a);
		free(num_arr);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	long long	*num_arr;
	int			word_count;
	t_stack		*a;
	t_stack		*b;

	word_count = 0;
	if (argc == 1)
		exit(0);
	num_arr = parsing_argument(argc, argv, &word_count);
	check_integer_and_duplicate(num_arr, word_count);
	check_if_arr_is_sorted(num_arr, word_count);
	make_stack_a_and_b(&a, &b, word_count, num_arr);
	free(num_arr);
	run_push_swap(&a, &b);
	return (0);
}
