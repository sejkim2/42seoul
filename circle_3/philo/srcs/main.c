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

int init_philo_manager(int argc, char **argv, t_manager *manager)
{
	manager->num_philosophers = ft_atoi(argv[1]);
	manager->num_fork = manager->num_philosophers;
	manager->time_to_die = ft_atoi(argv[2]);
	manager->time_to_eat = ft_atoi(argv[3]);
	manager->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		manager->num_of_must_eat = ft_atoi(argv[5]);
	else
		manager->num_of_must_eat = FALSE;
	manager->philo_table = malloc(sizeof(t_philo_info) * manager->num_philosophers);
	if (manager->philo_table == 0)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_manager manager;

	if (argc == 5 || argc == 6)
	{
		if (init_philo_manager(argc, argv, &manager) == FALSE)
			printf("system call error\n");

	}
	else
		printf("argument error\n");
	return (0);
}