#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	flag_minus;
	int	num;

	flag_minus = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag_minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (flag_minus == -1)
		return (-1 * num);
	else
		return (num);
}
