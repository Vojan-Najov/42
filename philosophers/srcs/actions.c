/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:11:26 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/07 17:42:46 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_ph *ph)
{
	pthread_mutex_lock(&ph->args->date_mutex);
	if (ph->args->simulation)
		printf("%10lu %d is thinking\n", gettimeofsimulation(ph->args), ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
}

static int	take_first_fork(t_ph *ph)
{
	pthread_mutex_lock(ph->first_fork);
	pthread_mutex_lock(&ph->args->date_mutex);
	if (!ph->args->simulation)
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		pthread_mutex_unlock(ph->first_fork);
		return (0);
	}
	printf("%10lu %d has taken a fork\n", gettimeofsimulation(ph->args), ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
	return (1);
}

static int	take_second_fork(t_ph *ph)
{
	if (ph->first_fork == ph->second_fork)
	{
		while (ph->args->simulation)
			usleep(ph->args->dtime);
		pthread_mutex_unlock(ph->first_fork);
		return (0);
	}
	pthread_mutex_lock(ph->second_fork);
	pthread_mutex_lock(&ph->args->date_mutex);
	if (!ph->args->simulation)
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		pthread_mutex_unlock(ph->first_fork);
		pthread_mutex_unlock(ph->second_fork);
		return (0);
	}
	gettimeofday(&ph->death_time, NULL);
	ph->death_time.tv_sec += \
						(ph->death_time.tv_usec + ph->args->dtime) / 1000000;
	ph->death_time.tv_usec = \
						(ph->death_time.tv_usec + ph->args->dtime) % 1000000;
	printf("%10lu %d is eating\n", gettimeofsimulation(ph->args), ph->id);
	++ph->eat_count;
	return (1);
}

void	philo_eat(t_ph *ph)
{
	if (!take_first_fork(ph))
		return ;
	if (!take_second_fork(ph))
		return ;
	if (ph->eat_count == ph->args->ecount)
	{
		++ph->args->eaters;
		if (ph->args->eaters == ph->args->phs_num)
			ph->args->simulation = 0;
		pthread_mutex_unlock(&ph->args->date_mutex);
	}
	pthread_mutex_unlock(&ph->args->date_mutex);
	ft_usleep(ph->args->etime, ph->args);
	pthread_mutex_unlock(ph->first_fork);
	pthread_mutex_unlock(ph->second_fork);
}

void	philo_sleep(t_ph *ph)
{
	pthread_mutex_lock(&ph->args->date_mutex);
	if (!ph->args->simulation)
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		return ;
	}
	printf("%10lu %d is sleeping\n", gettimeofsimulation(ph->args), ph->id);
	pthread_mutex_unlock(&ph->args->date_mutex);
	ft_usleep(ph->args->stime, ph->args);
}
