#include "philo.h"

static int	init_philosophers(t_ph **phs, int phs_num, pthread_mutex_t *forks);

static int	init_forks(pthread_mutex_t **forks, int phs_num);

static int	init_args(t_args **args, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_args			*args;
	t_ph			*phs;
	pthread_mutex_t	*forks;
	int			ret;
	//pthread_t	th;

	//args = NULL;
	ret = init_args(&args, argc, argv);
	printf("1\n");
	if (ret)
		return (ret);
	//forks = NULL;
	printf("2.0\n");
	ret = init_forks(&forks, args->phs_num);
	printf("2\n");
	
	if (ret)
		return (ret);
	phs = NULL;
	ret = init_philosophers(&phs, args->phs_num, forks);
	if (ret)
		return (ret);
	printf("%d\n", args->phs_num);
}

static int	init_forks(pthread_mutex_t **forks, int phs_num)
{
	int	i;
	int	ret;

	printf("a\n");
	*forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * phs_num);
	if (!*forks)
	{
		//free args
		write(STDERR_FILENO, "malloc error\n", sizeof("malloc_error\n"));
		return (MALLOC_ERROR);
	}
	i = 0;
	while (i < phs_num)
	{
		printf("hel %d\n", i);
		ret = pthread_mutex_init(*forks + i, NULL);
		if (ret)
		{
			// print error and free args
			return (ret);
		}
		++i;
	}
	return (0);
}

static int	init_args(t_args **args, int argc, char **argv)
{
	int	ret;

	*args = (t_args *) malloc(sizeof(t_args));
	if (!*args)
	{
		write(STDERR_FILENO, "malloc error\n", sizeof("malloc error\n"));
		return(MALLOC_ERROR);
	}
	(*args)->ecount = -1;
	ret = check_args(*args, argc, argv);
	if (!ret)
	{
		printf("args error\n");
		free(args);
		return (ARGS_ERROR);
	}
	printf("%d\n", (*args)->phs_num);
	return (0);
}

static int	init_philosophers(t_ph **phs, int phs_num, pthread_mutex_t *forks)
{
	int		i;
	int		idx;
	t_ph	*ph;

	*phs = (t_ph *) malloc(sizeof(t_ph) * phs_num);
	if (!*phs)
	{
		//free args and destroy forks and free forks;
		write(STDERR_FILENO, "malloc error\n", sizeof("malloc error\n"));
		return (MALLOC_ERROR);
	}
	i = 0;
	while (i < phs_num)
	{
		ph = *phs + i;
		ph->id = i + 1;
		if (i != phs_num - 1)
		{
			idx = (phs_num + i) % phs_num;
			ph->first = forks + idx;
			idx = (phs_num + i + 1) % phs_num;
			ph->second = forks + idx;
		}
		else
		{
			idx = 0;
			ph->first = forks + idx;
			idx = phs_num - 1;
			ph->second = forks + idx;
		}	
		++i;
	}
	return (0);
}
