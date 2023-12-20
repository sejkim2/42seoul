#include "../includes/philo.h"

int init_shared_info(t_share_info *shared, t_arg *arg)
{
    shared->fork = malloc(sizeof(pthread_mutex_t) * arg->num_fork);
    if (shared->fork == 0)
        return (FALSE);
    return (TRUE);
}