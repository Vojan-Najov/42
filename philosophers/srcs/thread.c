/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:43:33 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 15:49:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *vdata)
{
	t_ph		*ph;
	pthread_t	eye;

	ph = (t_ph *) vdata;
	pthread_mutex_lock(&ph->args->simul);
	pthread_mutex_unlock(&ph->args->simul);
	ph->death_time.tv_sec = ph->args->start.tv_sec + \
						((ph->args->start.tv_usec + ph->args->dtime) / 1000000);
	ph->death_time.tv_usec = \
						(ph->args->start.tv_usec + ph->args->dtime) % 1000000;
	ph->ret = pthread_create(&eye, NULL, watch, ph);
	if (ph->ret)
		return (&ph->ret);
	ph->ret = pthread_detach(eye);
	if (ph->ret)
		return (&ph->ret);
	if (ph->id % 2 == 0)
		ft_usleep(ph->args->etime, ph->args);
	while (ph->args->simulation)
	{
		philo_eat(ph);
		philo_sleep(ph);
		philo_think(ph);
	}
	return (NULL);
}
