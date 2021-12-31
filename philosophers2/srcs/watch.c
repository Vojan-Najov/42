/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:09:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/31 15:11:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(time_t now_sec, suseconds_t now_usec, t_ph *ph);

void	*watch(void *vph)
{
	struct timeval	now;
	t_ph			*ph;

	ph = (t_ph *) vph;
	while (1)
	{
		pthread_mutex_lock(&ph->args->date_mutex);
		if (!ph->args->simulation)
		{
			pthread_mutex_unlock(&ph->args->date_mutex);
			break ;
		}
		gettimeofday(&now, NULL);
		if (check_death(now.tv_sec, now.tv_usec, ph))
			continue ;
		ph->args->simulation = 0;
		printf("%10lu %d is died\n", gettimeofsimulation(ph->args), ph->id);
		pthread_mutex_unlock(&ph->args->date_mutex);
		break ;
	}
	return (NULL);
}

static int	check_death(time_t now_sec, suseconds_t now_usec, t_ph *ph)
{
	time_t		death_sec;
	suseconds_t	death_usec;

	death_sec = ph->death_time.tv_sec;
	death_usec = ph->death_time.tv_usec;
	if (now_sec < death_sec || (now_sec == death_sec && now_usec < death_usec))
	{
		pthread_mutex_unlock(&ph->args->date_mutex);
		ft_usleep((death_sec - now_sec) * 1000000 + (death_usec - now_usec), \
																	ph->args);
		return (1);
	}
	return (0);
}
