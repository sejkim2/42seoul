/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:25 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 16:21:03 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	free(philo->shared->fork);
	free(philo->shared);
	free(philo);
}

static void	print_error(t_error_type error_type)
{
	if (error_type == SYSTEM_CALL_ERROR)
		printf("system call error");
	else if (error_type == NUMBER_ERROR)
		printf("number error");
	else
		printf("argument error");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_error_type	error_type;
	t_arg			arg;
	t_philo			*philo;

	if (argc == 5 || argc == 6)
	{
		error_type = parse_argument(argc, argv, &arg);
		if (error_type != NOT_ERROR)
			print_error(error_type);
		else
		{
			philo = init_philosophers(arg, arg.num_philosophers);
			if (philo == NULL)
				print_error(SYSTEM_CALL_ERROR);
			else
			{
				error_type = run_simulation(philo, arg);
				free_philo(philo);
				if (error_type != NOT_ERROR)
					print_error(error_type);
			}
		}
	}
	else
		print_error(ARGUMENT_ERROR);
}
