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
	sem_wait(args->forks_sem);
	sem_wait(args->date_sem);
	gettimeofday(&args->death_time, NULL);
	args->death_time.tv_sec += ((args->death_time.tv_usec + args->dtime) / 1000000);
	args->death_time.tv_usec = (args->death_time.tv_usec + args->dtime) % 1000000;
	++args->eat_count;
	//if (ph->eat_count == ph->args->ecount)
	//{
	//	++ph->args->eaters;
	//	if (ph->args->eaters == ph->args->phs_num)
	//		ph->args->simulation = 0;
	//}
	printf("%10lu %d is eating\n", gettimeofsimulation(args), args->id);
	sem_post(args->date_sem);
	return (1);
}

void	philo_eat(t_args *args)
{
	if (!take_first_fork(args))
		return ;
	if (!take_second_fork(args))
		return ;
	usleep(args->etime);
	sem_post(args->forks_sem);
	sem_post(args->forks_sem);
}

void	philo_sleep(t_args *args)
{
	sem_wait(args->date_sem);
	printf("%10lu %d is sleeping\n", gettimeofsimulation(args), args->id);
	sem_post(args->date_sem);
	usleep(args->stime);
}
