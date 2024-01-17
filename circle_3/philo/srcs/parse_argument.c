#include "../includes/philo.h"

static int verify_sign(t_arg *arg)
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

static int verify_number(int argc, char **argv)
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

static  int set_argmuent(int argc, char **argv, t_arg *arg)
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
	if (init_shared_info(arg) == FALSE)
		return (FALSE);
	arg->is_finish = FALSE;
	arg->start_time = get_current_time();
	arg->global_must_eat_cnt = 0;
	return (TRUE);
		
}

static void init_argument(t_arg *arg)
{
	memset((void *)arg, 0, sizeof(t_arg));
}

int parse_argument(int argc, char **argv, t_arg *arg)
{
	init_argument(arg);
	if (verify_number(argc, argv) == FALSE)
		return (FALSE);
	if (set_argmuent(argc, argv, arg) == FALSE)
		return (FALSE);
	if (verify_sign(arg) == FALSE)
		return (FALSE);
	return (TRUE);
}
