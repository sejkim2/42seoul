#include "../includes/philo.h"

static void *thread_function(void *data)
{
    t_manager *manager;

    manager = (t_manager *)data;
    if (manager->)
}

int run_simulation(t_manager *manager)
{
    int i;

    i = 0;
    //철학자 수만큼 thread 생성 후 수행
    while (i < manager->num_philosophers)
    {
        if (pthread_create(&manager->philo_table[i], NULL, thread_function, (void *)manager))
			return (FALSE);
        i++;
    }
    //thread 종료
    i = 0;
    while (i < manager->num_philosophers)
    {
		pthread_join(&manager->philo_table[i], NULL);
        i++;
    }
    return (TRUE);
}
