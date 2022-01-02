/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:50:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 20:05:44 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	philosopher(t_args *args);

static int	launch_philos(t_args *args);

static int	wait_philos(t_args *args);

int	main(int argc, char **argv)
{
	int		ret;
	t_args	*args;

	args = (t_args *) malloc(sizeof(t_args));
	if (!args)
	{
		write(STDERR_FILENO, g_mal_err_mes, sizeof(g_mal_err_mes));
		return (MALLOC_ERROR);
	}
	ret = init_args(args, argc, argv);
	if (ret)
		return (ret);
	ret = launch_philos(args);
	if (ret)
		return (ret);
	wait_philos(args);
	completion(args, 1, 1, 1);
	return (0);
}

static int	launch_philos(t_args *args)
{
	int	ret;
	int	i;

	ret = gettimeofday(&args->start, NULL);
	if (ret)
	{
		//completion;
		return (GETTIME_ERROR);
	}
	i = -1;
	while (++i < args->phs_num)
	{
		args->id = i + 1;
		args->pids[i] = fork();
		if (args->pids[i] == -1)
		{
			//completion;
			return (FORK_ERROR);
		}
		else if (args->pids[i] == 0)
		{
			ret = philosopher(args);
			free(args);
			exit(ret);
		}
	}
	return (0);
}

static int	wait_philos(t_args *args)
{
	int	i;
	int	ret;

	sem_wait(args->end_sem);
	i = -1;
	while (++i < args->phs_num)
		kill(args->pids[i], SIGINT);
	i = -1;
	while (++i < args->phs_num)
		waitpid(-1, &ret, WUNTRACED);

	return (0);
}

int		check_death(time_t now_sec, suseconds_t now_usec, t_args *args)
{
	time_t		death_sec;
	suseconds_t	death_usec;

	death_sec = args->death_time.tv_sec;
	death_usec = args->death_time.tv_usec;
	if (now_sec < death_sec || (now_sec == death_sec && now_usec < death_usec))
	{
		sem_post(args->date_sem);
		ft_usleep((death_sec - now_sec) * 1000000 + (death_usec - now_usec), args);
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
		sem_post(args->end_sem);
		break ;
	}
	return (NULL);
}

static int	philosopher(t_args *args)
{
	int			i;
	int			ret;
	pthread_t	th;

	args->death_time.tv_sec = (args->start.tv_sec + \
						(args->start.tv_usec + args->dtime) / 1000000);
	args->death_time.tv_usec = (args->start.tv_usec + args->dtime) % 1000000;
	ret = pthread_create(&th, NULL, watch, args);
	if (ret)
		return (THREAD_ERROR);
	if (args->id % 2 == 0)
		ft_usleep(args->etime, args);
	i = -1;
	while (++i < 12)
	{
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
	}
	ret = pthread_detach(th);
	if (ret)
		return (JOIN_ERROR); //
	return (0);
}
