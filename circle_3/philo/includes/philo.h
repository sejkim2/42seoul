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
    MALLOC,
    NOT_ENOUGH_BOUNDARY
}   t_error;

typedef struct s_argument
{
    int num_philosophers;
    int num_fork;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_must_eat;
}   t_arg;

typedef struct s_share_info
{
    pthread_mutex_t *fork;
    pthread_mutex_t print;
    pthread_mutex_t start_time;
}   t_share_info;

typedef struct s_philo
{
    t_arg *arg;
    int id;
    int left_hand;
    int right_hand;
    int life_time;
    int count_eat;
    pthread_t thread;
    t_share_info shared;
}   t_philo;

int	ft_strlen(char *s);
int	ft_isdigit(int c);
int	ft_atoi(char *str);

int	main(int argc, char **argv);
int parse_argument(int argc, char **argv, t_arg *arg);
long long get_current_time(void);

#endif