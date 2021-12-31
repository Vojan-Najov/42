#include "philo_bonus.h"

void	philosopher(t_args *args);

int	main(int argc, char **argv)
{
	int		ret;
	int		i;
	t_args	args;

	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);
	i = -1;
	gettimeofday(&args.start, NULL);
	while (++i < args.phs_num)
	{
		args.id = i + 1;
		args.pids[i] = fork();
		if (args.pids[i] == -1)
		{
			//completion
			return (FORK_ERROR);
		}
		else if (args.pids[i] == 0)
		{
			philosopher(&args);
			return (0);
		}
	}
	sem_wait(args.death_sem);
	i = 0;
	while (i < args.phs_num)
	{
		kill(args.pids[i], SIGINT);
		++i;
	}
	//completion(&args, args.phs_num, 1, 1);
	return (0);
}

int		check_death(time_t now_sec, suseconds_t now_usec, t_args *args)
{
	time_t		death_sec;
	suseconds_t	death_usec;

	death_sec = args->death_time.tv_sec;
	death_usec = args->death_time.tv_usec;
	//printf("start: %ld   %ld\n", args->start.tv_sec, args->start.tv_usec);
	//printf("now  : %ld   %ld\n", now_sec, now_usec);
	//printf("death: %ld   %ld\n", death_sec, death_usec);
	if (now_sec < death_sec || (now_sec == death_sec && now_usec < death_usec))
	{
		sem_post(args->date_sem);
		usleep((death_sec - now_sec) * 1000000 + (death_usec - now_usec));
		return (1);
	}
	return (0);
}

void	*watch(void *vargs)
{
	struct timeval	now;
	t_args 			*args;

	args = (t_args *) vargs;
	while (1)
	{
		sem_wait(args->date_sem);
		gettimeofday(&now, NULL);
		if (check_death(now.tv_sec, now.tv_usec, args))
			continue;
		printf("%10lu %d is died\n", gettimeofsimulation(args), args->id);
		sem_post(args->death_sem);
	}
}

void	philosopher(t_args *args)
{
	int			i;
	pthread_t	th;

	args->death_time.tv_sec = (args->start.tv_sec + \
						(args->start.tv_usec + args->dtime) / 1000000);
	args->death_time.tv_usec = (args->start.tv_usec + args->dtime) % 1000000;
	i = 0;
	pthread_create(&th, NULL, watch, args);
	if (args->id % 2 == 0)
		usleep(args->etime);
	while (++i < 12)
	{
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
	}
	pthread_detach(th);
}
