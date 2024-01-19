/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:36:06 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 16:20:33 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_message(t_message_type message_type)
{
	if (message_type == TAKEN_FORK)
		printf("has taken a fork");
	else if (message_type == EATING)
		printf("is eating");
	else if (message_type == SLEEPING)
		printf("is sleeping");
	else if (message_type == THINKING)
		printf("is thinking");
	else
		printf("died");
	printf("\n");
}

void	philo_message(t_philo *philo, t_message_type message_type)
{
	long long	cur_time;

	pthread_mutex_lock(&(philo->shared->print));
	cur_time = get_current_time();
	if (philo->shared->is_finish == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->print));
		return ;
	}
	printf("%lld %d ", cur_time - philo->shared->start_time, philo->id);
	print_message(message_type);
	pthread_mutex_unlock(&(philo->shared->print));
}
