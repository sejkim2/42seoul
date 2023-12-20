/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:25 by sejkim2           #+#    #+#             */
/*   Updated: 2023/11/25 13:24:00 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int init_philosophers(t_philo **philo, t_arg *arg, int num)
{
    int i;

    *philo = malloc(sizeof(t_philo *) * num);
    if (*philo == 0)
        return (FALSE);
    i = 0;
    while (i < num)
    {
        (*philo)[i].arg = arg;
        (*philo)[i].id = i;
        (*philo)[i].left_hand = i;
        (*philo)[i].right_hand = (i + 1) % num;
        (*philo)[i].count_eat = 0;
        i++;
    }
    return (TRUE);
}

int	main(int argc, char **argv)
{
	t_arg arg;
	t_philo *philo;

	if (argc == 5 || argc == 6)
	{
		if (parse_argument(argc, argv, &arg) == FALSE)
			printf("system call error\n");
		else
		{
			if (init_philosophers(&philo, &arg, arg.num_philosophers) == FALSE)
				printf("system call error\n");
			// run_philo();
		}
	}
	else
		printf("argument error\n");
	return (0);
}