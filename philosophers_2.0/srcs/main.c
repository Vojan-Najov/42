#include "philo.h"

static int	init_threads(t_args *args);

static int	init_half_of_threads(t_args *args, int start);

static int	join_threads(t_args *args, void **value_ptr);

int	main(int argc, char **argv)
{
	int		ret;
	t_args	args;
	void	**value_ptr;

	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);
	value_ptr = malloc(sizeof(void *) * args.phs_num);
	if (!value_ptr)
	{
		completion(&args, args.phs_num, 1);
		return (MALLOC_ERROR);
	}
	ret = init_threads(&args);
	if (ret)
		return (ret);
	ret = join_threads(&args, value_ptr);
	free(value_ptr);
	completion(&args, args.phs_num, 1);
	return (ret);
}

static int	join_threads(t_args *args, void **value_ptr)
{
	int	i;
	int	ret;

	i = 0;
	while (i < args->phs_num)
	{
		ret = pthread_join(args->ths[i], value_ptr + i);
		if (ret || value_ptr[i])
			return (JOIN_ERROR);
		++i;
	}
	return (0);
}

static int	init_threads(t_args *args)
{
	int	ret;

	ret = init_half_of_threads(args, 0);
	if (ret)
		return (ret);
	//usleep(10000);
	usleep(args->etime);
	ret = init_half_of_threads(args, 1);
	if (ret)
		return (ret);
	return (0);
}

static int	init_half_of_threads(t_args *args, int start)
{
	int	i;
	int	ret;

	i = start;
	while (i < args->phs_num)
	{
		ret = pthread_create(args->ths + i, NULL, thread, &args->phs[i]);
		if (ret)
		{
			completion(args, args->phs_num, 1);
			write (STDERR_FILENO, g_thr_err_mes, sizeof(g_thr_err_mes));
			return (THREAD_ERROR);
		}
		i += 2;
	}
	return (0);
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


	struct timeval s;
	gettimeofday(&s, NULL);
	printf("%ld %03ld start simulation\n\n", s.tv_sec, s.tv_usec / 1000);
	args.simulation = 1;
	pthread_mutex_unlock(&args.simul);

*/

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

/*
	// threads initilization
	i = 0;
	while (i < args.phs_num)
	{
		pthread_create(args.ths + i, NULL, thread, &args.phs[i]);
		i += 2;
	}
	usleep(10000);
	i = 1;
	while (i < args.phs_num)
	{
		pthread_create(args.ths + i, NULL, thread, args.phs + i);
		i += 2;
	}
*/
