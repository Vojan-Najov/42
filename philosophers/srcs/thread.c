#include "philo.h"

static void	philo_think(t_ph *ph)
{
	struct timeval	tv;

	pthread_mutex_lock(&ph->args->write_mutex);	
	gettimeofday(&tv, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d is thinking\n", tv.tv_sec, tv.tv_usec / 1000, ph->id);
	pthread_mutex_unlock(&ph->args->write_mutex);
}

static void	philo_eat(t_ph *ph)
{
	struct timeval	tv;
	long int		tmp;

	pthread_mutex_lock(ph->first_fork);
	pthread_mutex_lock(&ph->args->write_mutex);
	gettimeofday(&tv, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d has taken a fork\n", tv.tv_sec, tv.tv_usec / 1000, ph->id);
	else
	{
		pthread_mutex_unlock(&ph->args->write_mutex);
		pthread_mutex_unlock(ph->first_fork);
		return ;
	}
	pthread_mutex_unlock(&ph->args->write_mutex);
	pthread_mutex_lock(ph->second_fork);
	pthread_mutex_lock(&ph->args->write_mutex);
	ph->eating = 1;
	gettimeofday(&tv, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, ph->id);
	else
	{
		pthread_mutex_unlock(&ph->args->write_mutex);
		pthread_mutex_unlock(ph->first_fork);
		pthread_mutex_unlock(ph->second_fork);
		return ;
	}
	pthread_mutex_unlock(&ph->args->write_mutex);

	usleep(ph->args->etime);

	// update death time
	gettimeofday(&tv, NULL);
	tmp = tv.tv_usec + ph->args->dtime / 1000000;
	ph->death_time.tv_sec += tmp;
	ph->death_time.tv_usec = (tv.tv_usec + ph->args->dtime) % 1000000;
	ph->eating = 0;

	pthread_mutex_unlock(ph->first_fork);
	pthread_mutex_unlock(ph->second_fork);
}

static void	philo_sleep(t_ph *ph)
{
	struct timeval	tv;

	pthread_mutex_lock(&ph->args->write_mutex);
	gettimeofday(&tv, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d is sleeping\n", tv.tv_sec, tv.tv_usec / 1000, ph->id);
	else
	{
		pthread_mutex_unlock(&ph->args->write_mutex);
		return ;
	}
	pthread_mutex_unlock(&ph->args->write_mutex);
	usleep(ph->args->stime);
}

void		*watch(void *vph)
{
	struct timeval	tv;
	t_ph			*ph;

	ph = (t_ph *) vph;
	pthread_mutex_lock(&ph->args->simul);
	pthread_mutex_unlock(&ph->args->simul);
	while (ph->args->simulation)
	{
		if (ph->eating)
			continue ;
		gettimeofday(&tv, NULL);
		if (tv.tv_sec < ph->death_time.tv_sec)
			continue;
		if (tv.tv_sec == ph->death_time.tv_sec && \
				tv.tv_usec < ph->death_time.tv_usec)
			continue ;
		if (ph->args->simulation)
		{
			ph->args->simulation = 0;
			pthread_mutex_lock(&ph->args->write_mutex);
			printf("%ld %03d  %d died\n", tv.tv_sec, tv.tv_usec / 1000, ph->id);
			pthread_mutex_unlock(&ph->args->write_mutex);
		}
	}
	return (NULL);
}

void		*thread(void *vdata)
{
	t_ph		*ph;
	pthread_t	eye;

	ph = (t_ph *) vdata;

	pthread_create(&eye, NULL, watch, ph);
	pthread_detach(eye);

	pthread_mutex_lock(&ph->args->simul);
	pthread_mutex_unlock(&ph->args->simul);
	while (ph->args->simulation)
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph);
	}
	
	return(NULL);
}
