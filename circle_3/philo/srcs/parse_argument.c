#include "../includes/philo.h"

static int verify_sign(t_arg *arg, t_error_type *error_type)
{
	if (arg->num_philosophers <= 0 || \
	arg->time_to_die < 0 || \
	arg->time_to_eat < 0 || \
	arg->time_to_sleep < 0 || \
	arg->num_of_must_eat < 0)
	{
		*error_type = NUMBER_ERROR;
		return (FALSE);
	}
	else
		return (TRUE);
}

static  int set_argmuent(int argc, char **argv, t_arg *arg, t_error_type *error_type)
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
	return (TRUE);
		
}

static int verify_number(int argc, char **argv, t_error_type *error_type)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_strlen(argv[i]) > 10)
		{
			*error_type = NUMBER_ERROR;
			return (FALSE);
		}
		while (j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == FALSE)
			{
				*error_type = NUMBER_ERROR;
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_error_type parse_argument(int argc, char **argv, t_arg *arg)
{
	t_error_type error_type;

	if (verify_number(argc, argv, &error_type) == FALSE)
		return (error_type);
	if (set_argmuent(argc, argv, arg, &error_type) == FALSE)
		return (error_type);
	if (verify_sign(arg, &error_type) == FALSE)
		return (error_type);
	return (NOT_ERROR);
}
