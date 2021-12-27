#include "philo.h"

static int	init_threads(t_args *args);

//static int	init_half_of_threads(t_args *args, int start);

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

static int init_threads(t_args *args)
{	
	int	i;
	int	ret;

	i = 0;
	pthread_mutex_lock(&args->simul);
	printf("hell\n");
	while (i < args->phs_num)
	{
		ret = pthread_create(args->ths + i, NULL, thread, &args->phs[i]);
		if (ret)
		{
			completion(args, args->phs_num, 1);
			write (STDERR_FILENO, g_thr_err_mes, sizeof(g_thr_err_mes));
			return (THREAD_ERROR);
		}
		++i;
	}
	gettimeofday(&args->start, NULL);
	pthread_mutex_unlock(&args->simul);
	return (0);
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

/*
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

*/
