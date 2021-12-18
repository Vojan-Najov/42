/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:50:06 by ccartman          #+#    #+#             */
/*   Updated: 2021/11/27 19:02:55 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	completion(t_args *args, int forks_num, int date_mutex, int simul_mutex)
{
	int	i;

	i = 0;
	while (i < forks_num)
	{
		pthread_mutex_destroy(args->forks + i);
		++i;
	}
	if (date_mutex)
		pthread_mutex_destroy(&args->date_mutex);
	if (simul_mutex)
		pthread_mutex_destroy(&args->date_mutex);
	free(args->phs);
	free(args->forks);
	free(args->ths);
}
