#include "philo.h"

int	main(int argc, char **argv)
{
	t_args		*args;
	int			ret;
	int			i;
	pthread_t	th;

	init_param(args);
	printf("%d\n", ph.philos_num);
	ph.data_mutex = malloc(sizeof(pthread_mutex_t));
	ret = pthread_mutex_init(ph.data_mutex, NULL);
	printf("hello %d\n", ret);
	for(i = 0; i < ph.philos_num; ++i)
	{
		printf("main id %d\n", i + 1);
		pthread_mutex_lock(ph.data_mutex);
		ph.id = i + 1;
		pthread_create(&th, NULL, philo_thread, &ph);
		pthread_mutex_unlock(ph.data_mutex);
		//usleep(1000);
	}
}

static void	init_param(t_args *args)
{
	args = (t_args *) malloc(sizeof(t_args));
	if (!args)
	{
		write(STDERR_FILENO, "malloc error\n", sizeof("malloc error\n"));
		exit(EXIT_FAILURE);
	}
	param.ecount = -1;
	ret = check_args(argc, argv, args);
	if (!ret)
	{
		printf("args error\n");
		exit(EXIT_FAILURE);
	}
	args->phs = (t_ph *) malloc(sizeof(t_ph) * param->philos_num);
	if (!args->phs)
	{
		write(STDERR_FILENO, "malloc error\n", sizeof("malloc error\n"));
		exit(EXIT_FAILURE);
	}
	args->forks = (pthread_mutex_t **) malloc(sizeof(pthread_mutex_t *) * args->philos_num);
	if (!args)
	{
		write(STDERR_FILENO, "malloc error\n", sizeof("malloc error\n"));
		exit(EXIT_FAILURE);  // needed free memory
	}
	init_mutexes(args);
	for(i = 0; i < param->philos_num; ++i)
	{
		init_philosopher(&args->phs[i], args->philos_num, i + 1);
	}
}

static void	init_philosopher(t_ph *ph, int n, int id)
{
	int	first;
	int	second;

	ph->id = id;
	firs = (n + id - 1) % n;
	second = (id + 1) % n;

}

static void init_mutexes(t_args *args)
{
	int				n;
	pthread_mutex_t	*forks;
	int				ret;

	n = args->philos_num;
	forks = args->forks;
	for (int i = 0; i < n; ++i)
	{
		ret = pthread_mutex_init(forks[i]);
		if (ret)
			; //mutex_init_error
	}
}
