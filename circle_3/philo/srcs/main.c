/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:25 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 12:45:35 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void free_philo(t_philo *philo)
{
	int i;

	i = 0;
	free(philo->shared->fork);
	free(philo->shared);
	free(philo);
}

static void print_error(t_error_type error_type)
{
	if (error_type == SYSTEM_CALL_ERROR)
		printf("system call error");
	else if (error_type == NOT_VERIFY_BOUNDARY)
		printf("not verify boundary");
	else if (error_type == NOT_NUMBER)
		printf("not number");
	else
		printf("argument error");
	printf("\n");
}

void laeks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_error_type error_type;
	t_arg arg;
	t_philo *philo;

	atexit(laeks);
	if (argc == 5 || argc == 6)
	{
		error_type = parse_argument(argc, argv, &arg);
		if (error_type != NOT_ERROR)
			print_error(error_type);
		else
		{
			philo = init_philosophers(arg, arg.num_philosophers);
			run_simulation(philo, arg);
			free_philo(philo);
		}
	}
	else
		print_error(ARGUMENT_ERROR);
	return (0);
}