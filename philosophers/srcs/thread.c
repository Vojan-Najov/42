#include "philo.h"

int			get_time_of_day_in_ms(void)
{
	struct timeval	tv;
	int				ms;

	gettimeofday(&tv, NULL);
	ms = ((int) tv.tv_sec * 1000)  + ((int) tv.tv_usec) / 1000;
	return (ms);
G}

static void	think(int id, pthread_mutex_t *write_mutex)
{
	int	ms;


	pthread_mutex_lock(write_mutex);
	ms = get_time_of_day_in_ms();
	printf("%d %d is thinking\n", ms, id);
	pthread_mutex_unlock(write_mutex);
}

static void	eat(t_ph *ph)
{
	int			id;
	int			ms;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	
	id = ph->id;
	write_mutex = &ph->args->write_mutex;
	first_fork = ph->first;
	second_fork = ph->second;
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(write_mutex);
	ms = get_time_of_day_in_ms();
	printf("%d %d has taken a fork\n", ms, id);
	pthread_mutex_unlock(write_mutex);
	pthread_mutex_lock(second_fork);
	pthread_mutex_lock(write_mutex);
	ms = get_time_of_day_in_ms();
	printf("%d %d has taken a fork\n", ms, id);
	ms = get_time_of_day_in_ms();
	printf("%d %d is eating\n", ms, id);
	pthread_mutex_unlock(write_mutex);
	usleep(ph->args->etime);
	ms = get_time_of_day();
	ph->lasteattime = ms;
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);	
}

static void	philo_sleep(int id, pthread_mutex_t *write_mutex, int stime)
{
	int	ms;

	pthread_mutex_lock(write_mutex);
	ms = get_time_of_day_in_ms();
	printf("%d %d is sleeping\n", ms, id);
	pthread_mutex_unlock(write_mutex);
	usleep(stime);
}

static void	philo_think(t_ph ph)
{
	if (ph.args.simulation)
						
}

void		*thread(void *vdata)
{
	t_ph	*ph;

	ph = (t_ph *) vdata;
	pthread_mutex_lock(&ph->args->simul);
	pthread_mutex_unlock(&ph->args->simul);
	while (simulation)
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph->id, &ph->args->write_mutex, ph->args->stime);
	}
	
	return(NULL);
}
