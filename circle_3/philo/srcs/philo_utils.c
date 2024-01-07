#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_atoi(char *str)
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

long long get_current_time(void)
{
    struct timeval time;
    long long result;

    if (gettimeofday(&time, NULL) == -1)
		return (FALSE);
    //1초 : 0.001ms, 1초 : 0.000001us
    result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return result;
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void run_time(t_philo *philo, long long t_time)
{
	long long s = get_current_time();
    long long cur_time;
    while (philo->arg->is_finish == FALSE)
    {
        cur_time = get_current_time() - s;
        if (cur_time - philo->life_time >= t_time)
            break ;
    }
}
