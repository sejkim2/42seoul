/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:55:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/23 15:07:52 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE  1
# define FALSE 0
# define INTEGER_MAX 2147483647
# define INTEGER_MIN -2147483648

typedef enum e_error_type
{
	NOT_ERROR = 0,
	SYSTEM_CALL_ERROR,
	NUMBER_ERROR,
	ARGUMENT_ERROR
}	t_error_type;

typedef enum e_message_type
{
	TAKEN_FORK_LEFT = 0,
	TAKEN_FORK_RIGHT,
	PUT_FORK_LEFT,
	PUT_FORK_RIGHT,
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_message_type;

typedef struct s_share_info
{
	int				is_finish;
	int				global_must_eat_cnt;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	must_eat_cnt;
	pthread_mutex_t	check_finish;
	pthread_mutex_t	time_update;
}	t_shared_info;

typedef struct s_argument
{
	int	num_philosophers;
	int	num_fork;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
}	t_arg;

typedef struct s_philo
{
	t_arg			arg;
	int				id;
	int				left_hand;
	int				right_hand;
	long long		last_eat_time;
	long long		start_time;
	int				count_eat;
	pthread_t		thread;
	t_shared_info	*shared;
}	t_philo;

int				ft_strlen(char *s);
int				ft_isdigit(int c);
int				ft_atoi(char *str);
long long		get_current_time(void);

t_error_type	parse_argument(int argc, char **argv, t_arg *arg);
t_philo			*init_philosophers(t_arg arg, int num);
t_shared_info	*init_shared_info(int num_fork);
t_error_type	run_simulation(t_philo *philo, t_arg arg);
void			run_time(t_philo *philo, long long required_time);
void			philo_message(t_philo *philo, t_message_type message_type);
void			*thread_function(void *data);
void			run_eating(t_philo *philo);
void			run_sleeping(t_philo *philo);
void			run_thinking(t_philo *philo);
int				checking_is_die(t_philo *philo);

#endif