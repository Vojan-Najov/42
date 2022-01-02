/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:13:04 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 15:48:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time, t_args *args)
{
	struct timeval	now;
	struct timeval	start;
	long	lasttime;

	gettimeofday(&start, NULL);
	while (args->simulation)
	{
		gettimeofday(&now, NULL);
		lasttime = now.tv_usec - start.tv_usec;
		if (lasttime < 0)
		{
			--now.tv_sec;
			lasttime += 1000000;
		}
		lasttime += (now.tv_sec - start.tv_sec) * 1000000;
		if (lasttime >= time)
			break ;
		usleep(50);
	}
}
