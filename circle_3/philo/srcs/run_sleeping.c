/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sleeping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:03:57 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/23 15:04:23 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	run_sleeping(t_philo *philo)
{
	philo_message(philo, SLEEPING);
	run_time(philo, philo->arg.time_to_sleep);
}
