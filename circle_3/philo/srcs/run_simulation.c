/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:35:53 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/23 15:10:42 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_philo_died(t_philo *philo, t_arg arg)
{
	int				i;
	long long		cur_time;

	while (1)
	{
		if (checking_is_die(philo) == TRUE)
			return ;
		i = 0;
		while (i < arg.num_philosophers)
		{
			cur_time = get_current_time();
			pthread_mutex_lock(&(philo->shared->time_update));
			if (cur_time - philo[i].last_eat_time >= arg.time_to_die)
			{
				philo_message(&philo[i], DIED);
				pthread_mutex_lock(&(philo->shared->check_finish));
				philo->shared->is_finish = TRUE;
				pthread_mutex_unlock(&(philo->shared->check_finish));
				pthread_mutex_unlock(&(philo->shared->time_update));
				return ;
			}
			pthread_mutex_unlock(&(philo->shared->time_update));
			i++;
		}
	}
}

t_error_type	run_simulation(t_philo *philo, t_arg arg)
{
	int	i;	

	i = 0;
	while (i < arg.num_philosophers)
	{
		if (pthread_create(&(philo[i].thread), NULL, \
		thread_function, &philo[i]) == 1)
			return (SYSTEM_CALL_ERROR);
		i++;
	}
	check_philo_died(philo, arg);
	i = 0;
	while (i < arg.num_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (NOT_ERROR);
}
