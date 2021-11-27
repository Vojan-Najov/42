#include "philo.h"

void	think(int id, pthread_mutex_t *write_mutex)
{
	struct timeval tv;

	pthread_mutex_lock(write_mutex);
	gettimeofday(&tv, NULL);
	printf("%ld %d %d is thinking\n", tv.tv_sec, tv.tv_usec / 1000, id);
	pthread_mutex_unlock(write_mutex);
}

void	*thread(void *vdata)
{
	t_ph	*ph;

	ph = (t_ph *) vdata;
	think(ph->id, &ph->args->write_mutex);
	//printf("%d\n", ph->id);
	return(NULL);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_args	args;
	int		i;
	pthread_t	th;


	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);
	i = 0;
	while (i < args.phs_num)
	{
		pthread_create(&th, NULL, thread, &args.phs[i]);
		pthread_detach(th);
		++i;
	}
	printf("hell\n");
	usleep(10000);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_args			*args;
	t_ph			*phs;
	pthread_mutex_t	*forks;
	int			ret;
	//pthread_t	th;

	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);
	ret = init_forks(&forks, args->phs_num);
	if (ret)
		return (ret);
	phs = NULL;
	ret = init_philosophers(&phs, args->phs_num, forks);
	if (ret)
		return (ret);
	printf("%d\n", args->phs_num);
}
*/
