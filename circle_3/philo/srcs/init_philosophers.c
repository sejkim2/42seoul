#include "../includes/philo.h"

int init_philosophers(t_philo **philo, t_arg *arg, int num)
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
        if (i == 0)
            (*philo)[i].right_hand = num - 1;
        else
            (*philo)[i].right_hand = (i - 1) % num;
        (*philo)[i].last_eat_time = arg->start_time;
        (*philo)[i].count_eat = 0;
        i++;
    }
    return (TRUE);
}