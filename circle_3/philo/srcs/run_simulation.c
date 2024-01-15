#include "../includes/philo.h"

static void print_message(t_message_type message_type)
{
    // if (message_type == TAKEN_FORK_LEFT)
    //     printf("has taken a left fork");
    // else if (message_type == TAKEN_FORK_RIGHT)
    //     printf("has taken a right fork");
    // else if (message_type == PUT_FORK_LEFT)
    //     printf("has put a left fork");
    // else if (message_type == PUT_FORK_RIGHT)
    //     printf("has put a right fork");
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

void philo_message(t_arg *arg, int philo_id, t_message_type message_type)
{
    long long cur_time;

    pthread_mutex_lock(&(arg->shared.print));
    cur_time = get_current_time();
    if (arg->is_finish == TRUE)
    {
        pthread_mutex_unlock(&(arg->shared.print));
        return ;
    }
    printf("%lld %d ", cur_time - arg->start_time, philo_id);
    print_message(message_type);
    pthread_mutex_unlock(&(arg->shared.print));
}

void run_eating(t_philo *philo)
{
    //hold on fork
    pthread_mutex_lock(&(philo->arg->shared.fork[philo->left_hand]));
    // philo_message(philo->arg, philo->last_eat_time, philo->id, TAKEN_FORK_LEFT);
    philo_message(philo->arg, philo->id, TAKEN_FORK);
    pthread_mutex_lock(&(philo->arg->shared.fork[philo->right_hand]));
    // philo_message(philo->arg, philo->last_eat_time, philo->id, TAKEN_FORK_RIGHT);
    philo_message(philo->arg, philo->id, TAKEN_FORK);

    //eat
    philo_message(philo->arg, philo->id, EATING);
    
    //time update
    //remove mutex??
    pthread_mutex_lock(&(philo->arg->shared.time_update));
    philo->last_eat_time = get_current_time();
    (philo->count_eat)++;
    pthread_mutex_unlock(&(philo->arg->shared.time_update));

    //spend eating time
    run_time(philo, philo->arg->time_to_eat);

    //put down fork
    // philo_message(philo->arg, philo->last_eat_time, philo->id, PUT_FORK);
    // philo_message(philo->arg, philo->last_eat_time, philo->id, PUT_FORK_RIGHT);
    // philo_message(philo->arg, philo->last_eat_time, philo->id, PUT_FORK_LEFT);
    pthread_mutex_unlock(&(philo->arg->shared.fork[philo->right_hand]));
    pthread_mutex_unlock(&(philo->arg->shared.fork[philo->left_hand]));
}

void run_sleeping(t_philo *philo)
{
    philo_message(philo->arg, philo->id, SLEEPING);
    run_time(philo, philo->arg->time_to_sleep);
}

void run_thinking(t_philo *philo)
{
    philo_message(philo->arg, philo->id, THINKING);
}

void *thread_function(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if ((philo->id) % 2 == 0)
        usleep(philo->arg->time_to_eat);
    while (philo->arg->is_finish == FALSE)
    {
        run_eating(philo);
        // if (philo->arg->num_of_must_eat && philo->count_eat == philo->arg->num_of_must_eat)
        // {
        //     philo->arg->is_finish = TRUE;
        //     break ;
        // }
        run_sleeping(philo);
        run_thinking(philo);
    }
    return (NULL);
}

int run_simulation(t_philo *philo, t_arg *arg)
{
    int i;
    long long cur_time;

    i = 0;
    while (i < arg->num_philosophers)
    {
        if (pthread_create(&(philo[i].thread), NULL, thread_function, &(philo[i])) == 1)
			return (FALSE);
        i++;
    }
    while (arg->is_finish == FALSE)
    {
        i = 0;
        while (i < arg->num_philosophers)
        {
            cur_time = get_current_time();
            if (cur_time - philo[i].last_eat_time >= arg->time_to_die)
            {
                printf("died time : %lld\n", cur_time - philo[i].last_eat_time);
                // printf("last eat : %lld\n", philo[i].last_eat_time);
                philo_message(arg, philo[i].id, DIED);
                arg->is_finish = TRUE;
                break ;
            }
            i++;
        }
    }
    i = 0;
    while (i < arg->num_philosophers)
    {
		pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (TRUE);
}
