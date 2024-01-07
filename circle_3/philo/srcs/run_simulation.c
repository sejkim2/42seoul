#include "../includes/philo.h"

void philo_message(t_share_info *shared, long long ms, int philo_id, t_message_type message_type)
{
    long long cur_time;

    pthread_mutex_lock(&(shared->print));
    cur_time = get_current_time();
    printf("%lld %d ", cur_time - ms, philo_id);
    if (message_type == TAKEN_FORK)
        printf("has taken a fork");
    else if (message_type == EATING)
        printf("is eating");
    else if (message_type == SLEEPING)
        printf("is sleeping");
    else if (message_type == THINKING)
        printf("is thinking");
    else
        printf("died");
    printf("\n");
    pthread_mutex_unlock(&(shared->print));
}

void run_eating(t_philo *philo)
{
    //hold on fork
    pthread_mutex_lock(&(philo->arg->shared.fork[philo->left_hand]));
    philo_message(&philo->arg->shared, philo->life_time, philo->id, TAKEN_FORK);
    pthread_mutex_lock(&(philo->arg->shared.fork[philo->right_hand]));
    philo_message(&philo->arg->shared, philo->life_time, philo->id, TAKEN_FORK);

    //eat
    philo_message(&philo->arg->shared, philo->life_time, philo->id, EATING);
    
    //time update
    // pthread_mutex_lock(&(philo->arg->shared.time_update));
    philo->life_time = get_current_time();
    // pthread_mutex_unlock(&(philo->arg->shared.time_update));

    //spend eating time
    (philo->count_eat)++;
    run_time(philo, philo->arg->time_to_eat);

    //put down fork
    pthread_mutex_unlock(&(philo->arg->shared.fork[philo->right_hand]));
    pthread_mutex_unlock(&(philo->arg->shared.fork[philo->left_hand]));
}

void run_sleeping(t_philo *philo)
{
    philo_message(&philo->arg->shared, philo->life_time, philo->id, SLEEPING);
    run_time(philo, philo->arg->time_to_sleep);
}

void run_thinking(t_philo *philo)
{
    philo_message(&philo->arg->shared, philo->life_time, philo->id, THINKING);
}

void *thread_function(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if ((philo->id) % 2 == 0)
        usleep(1000);
    while (philo->arg->is_finish == FALSE)
    {
        run_eating(philo);
        if (philo->arg->num_of_must_eat && philo->count_eat == philo->arg->num_of_must_eat)
        {
            philo->arg->is_finish = TRUE;
            break ;
        }
        run_sleeping(philo);
        run_thinking(philo);
    }
    return (NULL);
}

int run_simulation(t_philo *philo, t_arg *arg)
{
    int i;

    i = 0;
    while (i < arg->num_philosophers)
    {
        if (pthread_create(&philo[i].thread, NULL, thread_function, (void *)&(philo[i])) == 1)
			return (FALSE);
        i++;
    }
    i = 0;
    while (i < arg->num_philosophers)
    {
		pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (TRUE);
}
