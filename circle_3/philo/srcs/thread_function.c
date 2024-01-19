/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:38:21 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 18:13:27 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	run_sleeping(t_philo *philo)
{
	if (philo->shared->is_finish == FALSE)
	{
		philo_message(philo, SLEEPING);
		run_time(philo, philo->arg.time_to_sleep);
	}
}

static void	run_thinking(t_philo *philo)
{
	if (philo->shared->is_finish == FALSE)
	{
		philo_message(philo, THINKING);
		usleep(100);
	}
}

static	void	delay_even_philo(int philo_id, t_arg arg)
{
	if ((philo_id) % 2 == 0)
		usleep(arg.time_to_eat + 10);
}

void	*thread_function(void *data)
{
	t_philo		*philo;
	t_arg		arg;

	philo = (t_philo *)data;
	arg = philo->arg;
	delay_even_philo(philo->id, arg);
	while (philo->shared->is_finish == FALSE)
	{
		run_eating(philo);
		if (arg.num_philosophers == 1)
		{
			while (philo->shared->is_finish == FALSE)
				usleep(1);
			return (NULL);
		}
		if (arg.num_of_must_eat && \
		philo->shared->global_must_eat_cnt == arg.num_philosophers)
		{
			philo->shared->is_finish = TRUE;
			return (NULL);
		}
		run_sleeping(philo);
		run_thinking(philo);
	}
	return (NULL);
}
