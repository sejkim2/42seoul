#include "../includes/philo.h"

void *thread_function(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
}

int run_simulation(t_philo *philo, t_arg *arg)
{
    int i;

    i = 0;
    //철학자 수만큼 thread 생성 후 수행
    while (i < arg->num_philosophers)
    {
        if (pthread_create(&(philo[i].thread), NULL, thread_function, (void *)philo) == 1)
			return (FALSE);
        i++;
    }
    //thread 종료
    i = 0;
    while (i < arg->num_philosophers)
    {
		pthread_join(&(philo[i].thread), NULL);
        i++;
    }
    return (TRUE);
}
