#include "../includes/philo.h"

int init_shared_info(t_share_info *shared, t_arg *arg)
{
    int i;

    i = 0;
    shared->fork = malloc(sizeof(pthread_mutex_t) * arg->num_fork);
    if (shared->fork == 0)
        return (FALSE);
    while (i < arg->num_fork)
    {
        if (pthread_mutex_init(&(shared->fork[i]), NULL) == -1)
            return (FALSE);
        i++;
    }
    if (pthread_mutex_init(&(shared->print), NULL) == -1)
        return (FALSE);
    if (pthread_mutex_init(&(shared->start_time), NULL) == -1)
        return (FALSE);
    return (TRUE);
}