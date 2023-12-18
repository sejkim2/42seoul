#include "../includes/philo.h"

static int check_is_number(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int check_is_minus(t_manager *manager)
{
	if (manager->num_philosophers <= 0 || \
	manager->time_to_die < 0 || \
	manager->time_to_eat < 0 || \
	manager->time_to_sleep < 0 || \
	manager->num_of_must_eat < 0)
		return (FALSE);
	else
		return (TRUE);
}

int init_philo_manager(int argc, char **argv, t_manager *manager)
{
	if (check_is_number(argc, argv) == FALSE)
		return (FALSE);
	manager->num_philosophers = ft_atoi(argv[1]);
	manager->num_fork = manager->num_philosophers;
	manager->time_to_die = ft_atoi(argv[2]);
	manager->time_to_eat = ft_atoi(argv[3]);
	manager->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		manager->num_of_must_eat = ft_atoi(argv[5]);
	else
		manager->num_of_must_eat = FALSE;
	if (check_is_minus(manager) == FALSE)
		return (FALSE);
	manager->philo_table = malloc(sizeof(t_philo_info) * manager->num_philosophers);
	if (manager->philo_table == 0)
		return (FALSE);
	return (TRUE);
}