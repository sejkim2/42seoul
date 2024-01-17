/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:39:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/18 18:24:29 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philosophers(t_philo **philo, t_arg *arg, int num)
{
	int	i;

	*philo = malloc(sizeof(t_philo *) * num);
	if (*philo == 0)
		return (SYSTEM_CALL_ERROR);
	i = 0;
	while (i < num)
	{
		(*philo)[i].arg = *arg;
		(*philo)[i].id = i;
		(*philo)[i].left_hand = i;
		if (i == 0)
			(*philo)[i].right_hand = num - 1;
		else
			(*philo)[i].right_hand = (i - 1) % num;
		(*philo)[i].last_eat_time = arg->start_time;
		(*philo)[i].count_eat = 0;
		i++;
	}
	return (NOT_ERROR);
}