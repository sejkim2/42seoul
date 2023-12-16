/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:55:28 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/21 19:02:47 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

#define TRUE  1
#define FALSE 0

typedef enum e_error_num
{
    SYSTEM_CALL = 0,
    NUMERIC,
    ARGUMENT
}   t_error_num;

typedef struct s_philo_info
{
    int id;
    int left_hand;
    int right_hand;
    int life_time;
    int count_eat;
}   t_philo_info;

typedef struct s_philo_manager
{
    int num_philosophers;
    int num_fork;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_must_eat;
    t_philo_info *philo_table;
}   t_manager;

int	ft_atoi(const char *str);


#endif