#include "philo.h"

/*
static void	philo_think(t_ph *ph)
{
	struct timeval	now;

	pthread_mutex_lock(&ph->args->date_mutex);	
	gettimeofday(&now, NULL);
	if (ph->args->simulation)
		printf("%ld %03ld  %d is thinking\n", now.tv_sec, now.tv_usec / 1000, ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
}

static void	philo_eat(t_ph *ph)
{
	struct timeval	now;

	pthread_mutex_lock(ph->first_fork);
	pthread_mutex_lock(&ph->args->date_mutex);
	gettimeofday(&now, NULL);
	if (!ph->args->simulation)
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		pthread_mutex_unlock(ph->first_fork);
		return ;
	}
	printf("%ld %03ld  %d has taken a fork\n", now.tv_sec, now.tv_usec / 1000, ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
	pthread_mutex_lock(ph->second_fork);
	pthread_mutex_lock(&ph->args->date_mutex);
	if (!ph->args->simulation)
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		pthread_mutex_unlock(ph->first_fork);
		pthread_mutex_unlock(ph->second_fork);
		return ;
	}
	gettimeofday(&now, NULL);
	ph->death_time.tv_sec += (now.tv_usec + ph->args->dtime) / 1000000;
	ph->death_time.tv_usec = (now.tv_usec + ph->args->dtime) % 1000000;
	++ph->eat_count;
	printf("%ld %03ld  %d is eating\n", now.tv_sec, now.tv_usec / 1000, ph->id);
	if (ph->eat_count == ph->args->ecount)
	{
		++ph->args->eaters;
		if (ph->args->eaters == ph->args->phs_num)
			ph->args->simulation = 0;
	}
	pthread_mutex_unlock(&ph->args->date_mutex);
	usleep(ph->args->etime);
	pthread_mutex_unlock(ph->first_fork);
	pthread_mutex_unlock(ph->second_fork);
}

static void	philo_sleep(t_ph *ph)
{
	struct timeval	now;

	pthread_mutex_lock(&ph->args->date_mutex);
	if (!ph->args->simulation)
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		return ;
	}
	gettimeofday(&now, NULL);
	printf("%ld %03ld  %d is sleeping\n", now.tv_sec, now.tv_usec / 1000, ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
	usleep(ph->args->stime);
}

void		*thread(void *vdata)
{
	t_ph		*ph;
	pthread_t	eye;

	ph = (t_ph *) vdata;
	pthread_mutex_lock(&ph->args->date_mutex);
	ph->ret = gettimeofday(&ph->death_time, NULL);
	if (ph->ret)
		return (&ph->ret);
	ph->death_time.tv_sec += ((ph->death_time.tv_usec + ph->args->dtime) / 1000000);
	ph->death_time.tv_usec = (ph->death_time.tv_usec + ph->args->dtime) % 1000000;
	ph->ret = pthread_create(&eye, NULL, watch, ph);
	if (ph->ret)
		return (&ph->ret);
	ph->ret = pthread_detach(eye);
	if (ph->ret)
		return (&ph->ret);
	pthread_mutex_unlock(&ph->args->date_mutex);
	if (ph->id % 2)
		//usleep(ph->args->etime);
		usleep(10000);
	while (ph->args->simulation)
	{
		philo_eat(ph);
		philo_sleep(ph);
		philo_think(ph);
	}
	return(NULL);
}
*/

void		*thread(void *vdata)
{
	t_ph		*ph;
	pthread_t	eye;

	ph = (t_ph *) vdata;
	pthread_mutex_lock(&ph->args->simul);
	pthread_mutex_unlock(&ph->args->simul);
	ph->death_time.tv_sec = ph->args->start.tv_sec + \
							((ph->args->start.tv_usec + ph->args->dtime) / 1000000);
	ph->death_time.tv_usec = (ph->args->start.tv_usec + ph->args->dtime) % 1000000;
	ph->ret = pthread_create(&eye, NULL, watch, ph);
	if (ph->ret)
		return (&ph->ret);
	ph->ret = pthread_detach(eye);
	if (ph->ret)
		return (&ph->ret);
	if (ph->id % 2 == 0)
		usleep(ph->args->etime);
		//usleep(10000);
	while (ph->args->simulation)
	{
		philo_eat(ph);
		philo_sleep(ph);
		philo_think(ph);
	}
	return(NULL);
}
