/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:32:57 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/19 15:35:38 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_atoi(char *str)
{
	int			i;
	int			flag_minus;
	long long	num;

	flag_minus = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag_minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (flag_minus == -1)
		num = num * -1;
	if (num > INTEGER_MAX || num < INTEGER_MIN)
		return (-1);
	return ((int)num);
}

/*1초 : 0.001ms, 1초 : 0.000001us*/
long long	get_current_time(void)
{
	struct timeval		time;
	long long			result;

	if (gettimeofday(&time, NULL) == -1)
		return (FALSE);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	run_time(t_philo *philo, long long required_time)
{
	long long	start_time;
	long long	cur_time;

	start_time = get_current_time();
	while (philo->shared->is_finish == FALSE)
	{
		cur_time = get_current_time();
		if (cur_time - start_time >= required_time)
			break ;
		usleep(100);
	}
}
