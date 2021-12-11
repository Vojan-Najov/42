#include "philo.h"

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

void		*watch(void *vph)
{
	struct timeval	now;
	t_ph			*ph;

	ph = (t_ph *) vph;
	while (1)
	{
		pthread_mutex_lock(&ph->args->date_mutex);
		if (!ph->args->simulation)
		{
			pthread_mutex_unlock(&ph->args->date_mutex);
			break ;
		}
		gettimeofday(&now, NULL);
		if ((now.tv_sec < ph->death_time.tv_sec) || (now.tv_sec == ph->death_time.tv_sec && \
				now.tv_usec < ph->death_time.tv_usec))
		{
			pthread_mutex_unlock(&ph->args->date_mutex);
			continue;
		}
		ph->args->simulation = 0;
		printf("%ld %03ld  %d died\n", now.tv_sec, now.tv_usec / 1000, ph->id);
		printf("%ld %03ld    death_time\n", ph->death_time.tv_sec, ph->death_time.tv_usec / 1000);
		printf("%ld %03ld    stop simulation\n", now.tv_sec, now.tv_usec / 1000);
		pthread_mutex_unlock(&ph->args->date_mutex);
		break ;
	}
	return (NULL);
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
	while (ph->args->simulation)
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph);
	}
	return(NULL);
}

/*

printf("%ld %03ld  %d   death_time\n", ph->death_time.tv_sec, ph->death_time.tv_usec / 1000, ph->id);
*/
