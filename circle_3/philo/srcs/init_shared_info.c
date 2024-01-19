#include "../includes/philo.h"

t_shared_info *init_shared_info(int num_fork)
{
    int i;
    t_shared_info *shared;

    i = 0;
    shared = malloc(sizeof(t_shared_info));
    if (shared == NULL)
        return (NULL);
    if (pthread_mutex_init(&(shared->print), NULL) == -1)
        return (NULL);
    if (pthread_mutex_init(&(shared->time_update), NULL) == -1)
        return (NULL);
    if (pthread_mutex_init(&(shared->must_eat_cnt), NULL) == -1)
        return (NULL);
	shared->is_finish = FALSE;
	shared->start_time = get_current_time();
    if (shared->start_time == FALSE)
        return (NULL);
	shared->global_must_eat_cnt = 0;
    shared->fork = malloc(sizeof(pthread_mutex_t) * num_fork);
    if (shared->fork == NULL)
    {
        free(shared);
        return (NULL);
    }
    while (i < num_fork)
    {
        if (pthread_mutex_init(&(shared->fork[i]), NULL) == -1)
        {
            free(shared->fork);
            free(shared);
            return (NULL);
        }
        i++;
    }
    return (shared);
}