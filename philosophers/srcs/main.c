#include "philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_args	args;
	int		i;
	pthread_t	th;


	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);

	pthread_mutex_create(&args->simul, NULL);
	pthread_mutex_lock(&args->simul);

	i = 0;
	while (i < args.phs_num)
	{
		pthread_create(&th, NULL, thread, &args.phs[i]);
		pthread_detach(th);
		++i;
	}

	for(int j = 0; j < args->phs_num; ++j)
	{
		struct timeval death_time;
		death_time = args.ph[j].death_time;
		gettimeofday(&death_time, NULL);
		death_time.tv_sec += (death_time.tv_usec + args.dtime * 1000) / 1000000;
		death_time.tv_usec = (death_time.tv_usec + 1000 * dtime) % 1000000;
	}
	args->simulation = 1;
	pthread_mutex_unlock(&args->simul);
	while (args->simulation)
	{
		for(int j = 0; j < args->phs_num, ++j)
		{
			ph_t ph = args->ph[j];
			if (ph.lasteattime + args->dtime > get_time_of_day_in_ms())
			{
				args->simulation = 0;
				pthread_mutex_lock(args->write_mutex);
				printf("%d %d died\n", get_time_of_day_in_ms(), ph.id);
				pthread_mutex_unlock(args->write_mutex);
			}
		}
	}
	//usleep(10000);
	return (0);
}
