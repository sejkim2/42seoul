/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:21:46 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 15:28:00 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	init_mutex(t_shared_info *shared, int num_fork)
{
	int	i;

	if (pthread_mutex_init(&(shared->print), NULL) == -1)
		return (FALSE);
	if (pthread_mutex_init(&(shared->time_update), NULL) == -1)
		return (FALSE);
	if (pthread_mutex_init(&(shared->must_eat_cnt), NULL) == -1)
		return (FALSE);
	shared->fork = malloc(sizeof(pthread_mutex_t) * num_fork);
	if (shared->fork == NULL)
		return (FALSE);
	i = 0;
	while (i < num_fork)
	{
		if (pthread_mutex_init(&(shared->fork[i]), NULL) == -1)
		{
			free(shared->fork);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_shared_info	*init_shared_info(int num_fork)
{
	int				i;
	t_shared_info	*shared;

	i = 0;
	shared = malloc(sizeof(t_shared_info));
	if (shared == NULL)
		return (NULL);
	shared->is_finish = FALSE;
	shared->start_time = get_current_time();
	if (shared->start_time == FALSE)
	{
		free(shared);
		return (NULL);
	}
	shared->global_must_eat_cnt = 0;
	if (init_mutex(shared, num_fork) == FALSE)
	{
		free(shared);
		return (NULL);
	}
	return (shared);
}
