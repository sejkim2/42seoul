/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:17:35 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 15:21:22 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	init_philo_member(int num, t_philo *philo, t_arg arg, \
t_shared_info *shared)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].arg = arg;
		philo[i].id = i + 1;
		philo[i].left_hand = i;
		if (i == 0)
			philo[i].right_hand = num - 1;
		else
			philo[i].right_hand = (i - 1) % num;
		philo[i].last_eat_time = shared->start_time;
		philo[i].count_eat = 0;
		philo[i].shared = shared;
		i++;
	}
}

t_philo	*init_philosophers(t_arg arg, int num)
{
	int				i;
	t_shared_info	*shared;
	t_philo			*philo;

	shared = init_shared_info(num);
	if (shared == NULL)
		return (NULL);
	philo = malloc(sizeof(t_philo) * num);
	if (philo == NULL)
		return (NULL);
	init_philo_member(num, philo, arg, shared);
	return (philo);
}
