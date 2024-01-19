#include "../includes/philo.h"

static void print_message(t_message_type message_type)
{
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
}

void philo_message(t_philo *philo, t_message_type message_type)
{
    long long cur_time;

    pthread_mutex_lock(&(philo->shared->print));
    cur_time = get_current_time();
    if (philo->shared->is_finish == TRUE)
    {
        pthread_mutex_unlock(&(philo->shared->print));
        return ;
    }
    printf("%lld %d ", cur_time - philo->shared->start_time, philo->id);
    print_message(message_type);
    pthread_mutex_unlock(&(philo->shared->print));
}

void run_eating(t_philo *philo)
{
    //hold on fork
    pthread_mutex_lock(&(philo->shared->fork[philo->left_hand]));
    philo_message(philo, TAKEN_FORK);
    if (philo->arg.num_philosophers == 1)
    {
        pthread_mutex_unlock(&(philo->shared->fork[philo->left_hand]));
        return ;
    }
    pthread_mutex_lock(&(philo->shared->fork[philo->right_hand]));
    philo_message(philo, TAKEN_FORK);

    //eat
    philo_message(philo, EATING);
    
    //spend eating time
    run_time(philo, philo->arg.time_to_eat);

    //time update
    //remove mutex??
    pthread_mutex_lock(&(philo->shared->time_update));
    philo->last_eat_time = get_current_time();
    (philo->count_eat)++;
    pthread_mutex_unlock(&(philo->shared->time_update));

    pthread_mutex_lock(&(philo->shared->must_eat_cnt));
    if (philo->count_eat == philo->arg.num_of_must_eat)
        philo->shared->global_must_eat_cnt++;
    pthread_mutex_unlock(&(philo->shared->must_eat_cnt));

    //put down fork
    pthread_mutex_unlock(&(philo->shared->fork[philo->right_hand]));
    pthread_mutex_unlock(&(philo->shared->fork[philo->left_hand]));
}

void run_sleeping(t_philo *philo)
{
    if (philo->shared->is_finish == FALSE)
    {
        philo_message(philo, SLEEPING);
        run_time(philo, philo->arg.time_to_sleep);
    }
}

void run_thinking(t_philo *philo)
{
    if (philo->shared->is_finish == FALSE)
    {
        philo_message(philo, THINKING);
        usleep(100);
    }
}

void *thread_function(void *data)
{
    t_philo *philo;
    t_arg arg;

    philo = (t_philo *)data;
    arg = philo->arg;

    if ((philo->id) % 2 == 0)
        usleep(arg.time_to_eat + 10);
    while (philo->shared->is_finish == FALSE)
    {
        run_eating(philo);
        if (arg.num_philosophers == 1)
        {
            while (philo->shared->is_finish == FALSE)
                usleep(1);
            break ;
        }
        if (arg.num_of_must_eat && philo->shared->global_must_eat_cnt == arg.num_philosophers)
        {
            philo->shared->is_finish = TRUE;
            break ;
        }
        run_sleeping(philo);
        run_thinking(philo);
    }
    return (NULL);
}

static void check_philo_died(t_philo *philo, t_arg arg)
{
    int i;
    long long cur_time;
    t_shared_info *shared;

    shared = philo[0].shared;
    while (shared->is_finish == FALSE)
    {
        i = 0;
        while (i < arg.num_philosophers)
        {
            cur_time = get_current_time();
            if (cur_time - philo[i].last_eat_time >= arg.time_to_die)
            {
                philo_message(&philo[i], DIED);
                shared->is_finish = TRUE;
                break ;
            }
            i++;
        }
    }
}

int run_simulation(t_philo *philo, t_arg arg)
{
    int i;

    i = 0;
    while (i < arg.num_philosophers)
    {
        if (pthread_create(&(philo[i].thread), NULL, thread_function, &philo[i]) == 1)
			return (FALSE);
        i++;
    }
    check_philo_died(philo, arg);
    i = 0;
    while (i < arg.num_philosophers)
    {
		pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (TRUE);
}
