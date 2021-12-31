/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:31 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/31 16:05:34 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(unsigned long time)
{
	struct timeval	now;
	struct timeval	start;
	unsigned long	lasttime;

	gettimeofday(&start, NULL);
	while (1)
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
