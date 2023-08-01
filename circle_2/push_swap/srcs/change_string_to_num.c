/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_string_to_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:28 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/26 13:21:47 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	long long	ft_atoll(const char *str)
{
	long long	num;
	int			i;
	int			flag_minus;

	num = 0;
	flag_minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag_minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0');
		if (num > 21474836470)
			return (2147483648);
	}
	if (flag_minus == -1)
		return (-1 * num);
	else
		return (num);
}

static	int	check_if_data_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static	void	free_num_tmp(char **num_tmp)
{
	int		i;
	char	*free_str;

	i = 0;
	while (num_tmp[i])
	{
		free_str = num_tmp[i];
		i++;
		free(free_str);
	}
	free(num_tmp);
}

static	void	parsing_long_str(char *argv, long long *num_arr, \
int *num_arr_index)
{
	int		i;
	char	**num_tmp;

	i = 0;
	num_tmp = ft_split(argv, ' ');
	if (num_tmp == 0)
	{
		write(2, "Error\n", 6);
		free(num_arr);
		exit(1);
	}
	while (num_tmp[i])
	{
		if (check_if_data_is_number(num_tmp[i]) == 0)
		{
			free_num_tmp(num_tmp);
			free(num_arr);
			write(2, "Error\n", 6);
			exit(1);
		}
		num_arr[(*num_arr_index)++] = ft_atoll(num_tmp[i]);
		i++;
	}
	free_num_tmp(num_tmp);
}

long long	*change_string_to_num(int num_size, int argc, char **argv)
{
	long long	*num_arr;
	int			i;
	int			index;

	num_arr = (long long *)malloc(sizeof(long long) * num_size);
	check_memory_error_in_change_string_to_num(num_arr);
	i = 1;
	index = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			parsing_long_str(argv[i], num_arr, &index);
		else
		{
			if (check_if_data_is_number(argv[i]) == 0)
			{
				free(num_arr);
				write(2, "Error\n", 6);
				exit(1);
			}
			num_arr[index++] = ft_atoll(argv[i]);
		}
		i++;
	}
	return (num_arr);
}
