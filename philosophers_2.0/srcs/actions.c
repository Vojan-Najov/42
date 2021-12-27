/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:46:27 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/16 17:20:57 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_ph *ph)
{
	struct timeval	now;

	pthread_mutex_lock(&ph->args->date_mutex);	
	gettimeofday(&now, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d is thinking\n", now.tv_sec, \
											now.tv_usec / 1000, ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
}

static int	take_first_fork(t_ph *ph)
{
	struct timeval	now;

	pthread_mutex_lock(ph->first_fork);
	pthread_mutex_lock(&ph->args->date_mutex);
	gettimeofday(&now, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d has taken a fork\n", now.tv_sec, \
												now.tv_usec / 1000, ph->id);
	else
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		pthread_mutex_unlock(ph->first_fork);
		return (0);
	}
	pthread_mutex_unlock(&ph->args->date_mutex);
	return (1);
}

static int	take_second_fork(t_ph *ph)
{
	struct timeval	now;

	if (ph->second_fork == ph->first_fork)
	{
		usleep(ph->args->dtime + 10000);
		return (0);
	}
	pthread_mutex_lock(ph->second_fork);
	pthread_mutex_lock(&ph->args->date_mutex);
	gettimeofday(&now, NULL);
	ph->death_time.tv_sec += (now.tv_usec + ph->args->dtime) / 1000000;
	ph->death_time.tv_usec = (now.tv_usec + ph->args->dtime) % 1000000;
	if (ph->args->simulation)
		printf("%ld %03d  %d is eating\n", now.tv_sec, now.tv_usec / 1000, \
																	ph->id);
	else
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		pthread_mutex_unlock(ph->first_fork);
		pthread_mutex_unlock(ph->second_fork);
		return (0);
	}
	++ph->eat_count;
	if (ph->eat_count == ph->args->ecount)
	{
		++ph->args->eaters;
		if (ph->args->eaters == ph->args->phs_num)
			ph->args->simulation = 0;
	}
	pthread_mutex_unlock(&ph->args->date_mutex);
	return (1);
}

void	philo_eat(t_ph *ph)
{
	if (!take_first_fork(ph))
		return ;
	if (!take_second_fork(ph))
		return ;
	usleep(ph->args->etime);
	pthread_mutex_unlock(ph->first_fork);
	pthread_mutex_unlock(ph->second_fork);
}

void	philo_sleep(t_ph *ph)
{
	struct timeval	now;

	pthread_mutex_lock(&ph->args->date_mutex);
	gettimeofday(&now, NULL);
	if (ph->args->simulation)
		printf("%ld %03d  %d is sleeping\n", now.tv_sec, \
											now.tv_usec / 1000, ph->id);
	else
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		return ;
	}
	pthread_mutex_unlock(&ph->args->date_mutex);
	usleep(ph->args->stime);
}
