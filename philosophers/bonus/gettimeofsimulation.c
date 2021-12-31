#include "philo_bonus.h"

unsigned long	gettimeofsimulation(t_args *args)
{
	time_t			start_sec;
	suseconds_t		start_usec;
	struct timeval	now;

	start_sec = args->start.tv_sec;
	start_usec = args->start.tv_usec;
	gettimeofday(&now, NULL);
	if (start_usec > now.tv_usec)
	{
		now.tv_usec += 1000000;
		now.tv_sec--;
	}
	//printf("now %ld\n", now.tv_sec);
	//printf("start %ld\n", start_sec);
	return (((now.tv_sec - start_sec) * 1000) + ((now.tv_usec - start_usec) / 1000));
}
