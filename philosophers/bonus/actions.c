#include "philo_bonus.h"

void	philo_think(t_args *args)
{
	sem_wait(args->date_sem);
	printf("%10lu %d is thinking\n", gettimeofsimulation(args), args->id);
	sem_post(args->date_sem);
}

static int	take_first_fork(t_args *args)
{
	sem_wait(args->forks_sem);
	sem_wait(args->date_sem);
	printf("%10lu %d has taken a fork\n", gettimeofsimulation(args), args->id);
	sem_post(args->date_sem);
	return (1);
}

static int	take_second_fork(t_args *args)
{
	static int	eat_count;

	sem_wait(args->forks_sem);
	sem_wait(args->date_sem);
	printf("%10lu %d is eating\n", gettimeofsimulation(args), args->id);
	gettimeofday(&args->death_time, NULL);
	args->death_time.tv_sec += ((args->death_time.tv_usec + args->dtime) / 1000000);
	args->death_time.tv_usec = (args->death_time.tv_usec + args->dtime) % 1000000;
	++eat_count;
	if (eat_count == args->ecount)
		sem_post(args->eaters_sem);
	sem_post(args->date_sem);
	return (1);
}

void	philo_eat(t_args *args)
{
	if (!take_first_fork(args))
		return ;
	if (!take_second_fork(args))
		return ;
	ft_usleep(args->etime, args);
	sem_post(args->forks_sem);
	sem_post(args->forks_sem);
}

void	philo_sleep(t_args *args)
{
	sem_wait(args->date_sem);
	printf("%10lu %d is sleeping\n", gettimeofsimulation(args), args->id);
	sem_post(args->date_sem);
	ft_usleep(args->stime, args);
}
