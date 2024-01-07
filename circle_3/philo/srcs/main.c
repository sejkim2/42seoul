/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:25 by sejkim2           #+#    #+#             */
/*   Updated: 2023/11/25 13:24:00 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_arg arg;
	t_philo *philo;

	if (argc == 5 || argc == 6)
	{
		if (parse_argument(argc, argv, &arg) == FALSE)
			printf("system call error\n");
		else
		{
			if (init_philosophers(&philo, &arg, arg.num_philosophers) == FALSE)
				printf("system call error\n");
			run_simulation(philo, &arg);
		}
	}
	else
		printf("argument error\n");
	return (0);
}