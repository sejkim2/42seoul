/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:38:21 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/23 15:25:25 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	checking_must_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->must_eat_cnt));
	if (philo->shared->global_must_eat_cnt == philo->arg.num_philosophers)
	{
		pthread_mutex_lock(&(philo->shared->check_finish));
		philo->shared->is_finish = TRUE;
		pthread_mutex_unlock(&(philo->shared->check_finish));
		pthread_mutex_unlock(&(philo->shared->must_eat_cnt));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->shared->must_eat_cnt));
	return (FALSE);
}

static	void	delay_even_philo(int philo_id, t_arg arg)
{
	if ((philo_id) % 2 == 0)
		usleep(arg.time_to_eat + 10);
}

void	*thread_function(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	delay_even_philo(philo->id, philo->arg);
	while (1)
	{
		if (checking_is_die(philo) == TRUE)
			return (NULL);
		run_eating(philo);
		if (philo->arg.num_philosophers == 1)
		{
			while (1)
			{
				if (checking_is_die(philo) == TRUE)
					return (NULL);
				usleep(1);
			}
		}
		if (checking_must_eat(philo) == TRUE)
			return (NULL);
		run_sleeping(philo);
		run_thinking(philo);
	}
	return (NULL);
}
