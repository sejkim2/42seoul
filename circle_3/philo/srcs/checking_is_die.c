/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_is_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:05:51 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/23 15:07:13 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	checking_is_die(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->check_finish));
	if (philo->shared->is_finish == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->check_finish));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->shared->check_finish));
	return (FALSE);
}
