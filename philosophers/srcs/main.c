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
	i = 0;
	pthread_mutex_create(&args->simul, NULL);
	pthread_mutex_lock(&args->simul);
	while (i < args.phs_num)
	{
		pthread_create(&th, NULL, thread, &args.phs[i]);
		pthread_detach(th);
		++i;
	}
	for(int j = 0; j < args->phs_num; ++j)
	{
		int ms = get_time_of_day_in_ms();
		ph_t ph = args.phs[j];
		ph.lasteattime = ms;
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
