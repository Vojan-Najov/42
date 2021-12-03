#include "philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_args	args;
	int		i;
	pthread_t	*th;
	void		**value_ptr;


	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);

	th = (pthread_t *) malloc( sizeof(pthread_t) * args.phs_num);
	value_ptr = malloc(sizeof(void *) * args.phs_num);
	pthread_mutex_init(&args.simul, NULL);
	pthread_mutex_lock(&args.simul);

	i = 0;
	while (i < args.phs_num)
	{
		pthread_create(th + i, NULL, thread, &args.phs[i]);

		//pthread_detach(th);
		++i;
	}
/*
	for(int j = 0; j < args.phs_num; ++j)
	{
		struct timeval *death_time;
		death_time = &args.phs[j].death_time;
		gettimeofday(death_time, NULL);
		(*death_time).tv_sec += ((*death_time).tv_usec + args.dtime) / 1000000;
		(*death_time).tv_usec += ((*death_time).tv_usec +  args.dtime) % 1000000;
	}
	printf("%ld %ld\n\n", args.phs[0].death_time.tv_sec, args.phs[0].death_time.tv_usec);

*/
	struct timeval s;
	gettimeofday(&s, NULL);
	printf("%ld %03d start simulation\n\n", s.tv_sec, s.tv_usec / 1000);
	args.simulation = 1;
	pthread_mutex_unlock(&args.simul);


		/*
	while (args.simulation)
	{
		usleep(1000000);
		args.simulation = 0;
		for(int j = 0; j < args.phs_num; ++j)
		{
			t_ph ph = args.phs[j];
			if (ph.lasteattime + args.dtime > get_time_of_day_in_ms())
			{
				args.simulation = 0;
				pthread_mutex_lock(&args.write_mutex);
				printf("%d %d died\n", get_time_of_day_in_ms(), ph.id);
				pthread_mutex_unlock(&args.write_mutex);
				break ;
			}
		}
	}
	while (args.simulation)
	{
		for (int j = 0; j < args.phs_num; ++j)
		{
			t_ph ph = args.phs[j];
			struct timeval	tv;
			gettimeofday(&tv, NULL);
			if (tv.tv_sec < ph.death_time.tv_sec \
			|| (tv.tv_sec == ph.death_time.tv_sec && tv.tv_usec < ph.death_time.tv_sec))
				continue;
			args.simulation = 0;
			pthread_mutex_lock(&args.write_mutex);
			printf("%ld %03d  %d died\n", tv.tv_sec, tv.tv_usec / 100, ph.id);
			pthread_mutex_unlock(&args.write_mutex);
			break ;
		}
	}

		*/
	i = 0;
	while (i < args.phs_num)
	{
		pthread_join(th[i], value_ptr + i);
		i++;
	}
	//usleep(1000000);
	//args.simulation = 0;
	//usleep(500);
	return (0);
}
