#include "../includes/philo.h"

static int check_is_minus(t_arg *arg)
{
	if (arg->num_philosophers <= 0 || \
	arg->time_to_die < 0 || \
	arg->time_to_eat < 0 || \
	arg->time_to_sleep < 0 || \
	arg->num_of_must_eat < 0)
		return (FALSE);
	else
		return (TRUE);
}

static int check_is_number(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static void set_argmuent(int argc, char **argv, t_arg *arg)
{
	arg->num_philosophers = ft_atoi(argv[1]);
	arg->num_fork = arg->num_philosophers;
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->num_of_must_eat = ft_atoi(argv[5]);
	else
		arg->num_of_must_eat = FALSE;
}

static void init_argument(t_arg *arg)
{
	memset((void *)arg, 0, sizeof(t_arg));
}

int parse_argument(int argc, char **argv, t_arg *arg)
{
	init_argument(arg);
	if (check_is_number(argc, argv) == FALSE)
		return (FALSE);
	set_argmuent(argc, argv, arg);
	if (check_is_minus(arg) == FALSE)
		return (FALSE);
	return (TRUE);
}
