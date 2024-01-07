#include "../includes/philo.h"

int init_shared_info(t_arg *arg)
{
    int i;

    i = 0;
    arg->shared.fork = malloc(sizeof(pthread_mutex_t) * arg->num_fork);
    if (arg->shared.fork == 0)
        return (FALSE);
    while (i < arg->num_fork)
    {
        if (pthread_mutex_init(&(arg->shared.fork[i]), NULL) == -1)
            return (FALSE);
        i++;
    }
    if (pthread_mutex_init(&(arg->shared.print), NULL) == -1)
        return (FALSE);
    if (pthread_mutex_init(&(arg->shared.time_update), NULL) == -1)
        return (FALSE);
    return (TRUE);
}