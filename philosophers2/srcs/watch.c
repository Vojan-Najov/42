#include "philo.h"

static int	check_death(time_t now_sec, suseconds_t now_usec, t_ph *ph);

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
		if (check_death(now.tv_sec, now.tv_usec, ph))
			continue;
		ph->args->simulation = 0;
		printf("%10lu %d is died\n", gettimeofsimulation(ph->args), ph->id);
		//printf("%ld %03ld  %d died\n", now.tv_sec, now.tv_usec / 1000, ph->id);
		pthread_mutex_unlock(&ph->args->date_mutex);
		break ;
	}
	return (NULL);
}

static int	check_death(time_t now_sec, suseconds_t now_usec, t_ph *ph)
{
	time_t		death_sec;
	suseconds_t	death_usec;

	death_sec = ph->death_time.tv_sec;
	death_usec = ph->death_time.tv_usec;
	if (now_sec < death_sec || (now_sec == death_sec && now_usec < death_usec))
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		//usleep(1000);
		usleep((death_sec - now_sec) * 1000000 + (death_usec - now_usec));
		return (1);
	}
	return (0);
}

/*
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
			usleep((ph->death_time.tv_sec - now.tv_sec) * 1000000 + (ph->death_time.tv_usec - \
					now.tv_usec));
			continue;
		}
		ph->args->simulation = 0;
		printf("%ld %03ld  %d died\n", now.tv_sec, now.tv_usec / 1000, ph->id);
		pthread_mutex_unlock(&ph->args->date_mutex);
		break ;
	}
	return (NULL);
}

*/
/*

		printf("%ld %03ld    death_time\n", ph->death_time.tv_sec, ph->death_time.tv_usec / 1000);
		printf("%ld %03ld    stop simulation\n", now.tv_sec, now.tv_usec / 1000);
*/
