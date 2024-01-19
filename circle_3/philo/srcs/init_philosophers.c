#include "../includes/philo.h"

t_philo *init_philosophers(t_arg arg, int num)
{
    int i;
    t_shared_info *shared;
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * num);
    if (philo == NULL)
        return (NULL);
    shared = init_shared_info(num);
    if (shared == NULL)
        return (NULL);
    i = 0;
    while (i < num)
    {
        philo[i].arg = arg;
        philo[i].id = i;
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
    return (philo);
}