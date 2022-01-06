/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:28:41 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/06 19:23:02 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_death(time_t now_sec, suseconds_t now_usec, t_args *args);

static void	*watch(void *vargs);

int	philosopher(t_args *args)
{
	int			ret;
	pthread_t	th;

	args->death_time.tv_sec = (args->start.tv_sec + \
						(args->start.tv_usec + args->dtime) / 1000000);
	args->death_time.tv_usec = (args->start.tv_usec + args->dtime) % 1000000;
	ret = pthread_create(&th, NULL, watch, args);
	if (ret)
		return (THREAD_ERROR);
	ret = pthread_detach(th);
	if (ret)
		return (DETACH_ERROR);
	if (args->id % 2 == 0)
		ft_usleep(args->etime, args);
	while (1)
	{
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
	}
	return (0);
}

static int	check_death(time_t now_sec, suseconds_t now_usec, t_args *args)
{
	time_t		death_sec;
	suseconds_t	death_usec;

	death_sec = args->death_time.tv_sec;
	death_usec = args->death_time.tv_usec;
	if (now_sec < death_sec || (now_sec == death_sec && now_usec < death_usec))
	{
		sem_post(args->date_sem);
		ft_usleep((death_sec - now_sec) * 1000000 + (death_usec - now_usec), \
																		args);
		return (1);
	}
	return (0);
}

static void	*watch(void *vargs)
{
	struct timeval	now;
	t_args			*args;

	args = (t_args *) vargs;
	while (1)
	{
		sem_wait(args->date_sem);
		gettimeofday(&now, NULL);
		if (check_death(now.tv_sec, now.tv_usec, args))
			continue ;
		printf("%10lu %d is died\n", gettimeofsimulation(args), args->id);
		sem_post(args->end_sem);
		break ;
	}
	return (NULL);
}
