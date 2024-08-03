/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_eating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:43:50 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/23 14:55:09 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	increase_eat_cnt(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->must_eat_cnt));
	philo->shared->global_must_eat_cnt++;
	pthread_mutex_unlock(&(philo->shared->must_eat_cnt));
}

void	run_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->fork[philo->left_hand]));
	philo_message(philo, TAKEN_FORK);
	if (philo->arg.num_philosophers == 1)
	{
		pthread_mutex_unlock(&(philo->shared->fork[philo->left_hand]));
		return ;
	}
	pthread_mutex_lock(&(philo->shared->fork[philo->right_hand]));
	philo_message(philo, TAKEN_FORK);
	philo_message(philo, EATING);
	pthread_mutex_lock(&(philo->shared->time_update));
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&(philo->shared->time_update));
	(philo->count_eat)++;
	if (philo->arg.num_of_must_eat == philo->count_eat)
		increase_eat_cnt(philo);
	run_time(philo, philo->arg.time_to_eat);
	pthread_mutex_unlock(&(philo->shared->fork[philo->right_hand]));
	pthread_mutex_unlock(&(philo->shared->fork[philo->left_hand]));
}
