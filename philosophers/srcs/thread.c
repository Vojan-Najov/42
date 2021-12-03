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
	// update death time
	gettimeofday(&tv, NULL);
	tmp = (tv.tv_usec + ph->args->dtime) / 1000000;
	ph->death_time.tv_sec += tmp;
	ph->death_time.tv_usec = (tv.tv_usec + ph->args->dtime) % 1000000;
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
		gettimeofday(&tv, NULL);
		if (tv.tv_sec < ph->death_time.tv_sec)
			continue;
		if (tv.tv_sec == ph->death_time.tv_sec && \
				tv.tv_usec < ph->death_time.tv_usec)
			continue ;
		//pthread_mutex_lock(&ph->args->simul);
		if (ph->args->simulation)
		{
			ph->args->simulation = 0;
			pthread_mutex_lock(&ph->args->write_mutex);
			printf("%ld %03d  %d died\n", tv.tv_sec, tv.tv_usec / 1000, ph->id);
			printf("%ld %03d    death_time\n", ph->death_time.tv_sec, ph->death_time.tv_usec / 1000);
			printf("%ld %03d    stop simulation\n", tv.tv_sec, tv.tv_usec / 1000);
			pthread_mutex_unlock(&ph->args->write_mutex);
		}
		//pthread_mutex_unlock(&ph->args->simul);
	}
	return (NULL);
}

void		*thread(void *vdata)
{
	t_ph		*ph;
	pthread_t	eye;

	ph = (t_ph *) vdata;
	pthread_mutex_lock(&ph->args->simul);
	ph->ret = gettimeofday(&ph->death_time, NULL);
	if (ph->ret)
		return (&ph->ret);
	ph->death_time.tv_sec += ((ph->death_time.tv_usec + ph->args->dtime) / 1000000);
	ph->death_time.tv_usec = (ph->death_time.tv_usec + ph->args->dtime) % 1000000;
	printf("%ld %03d  %d   death_time\n", ph->death_time.tv_sec, ph->death_time.tv_usec / 1000, ph->id);
	ph->ret = pthread_create(&eye, NULL, watch, ph);
	if (ph->ret)
		return (&ph->ret);
	ph->ret = pthread_detach(eye);
	if (ph->ret)
		return (&ph->ret);
	pthread_mutex_unlock(&ph->args->simul);
	while (ph->args->simulation)
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph);
	}
	
	return(NULL);
}
