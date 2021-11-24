/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:54:12 by ccartman          #+#    #+#             */
/*   Updated: 2021/11/24 20:10:09 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *v_data)
{
	t_init	*ph;
	int		id;
	int		ret;

	ph = (t_init *) v_data;
	ret = pthread_mutex_lock(ph->data_mutex);
	printf("mutex ret %d\n", ret);
	id = ph->id;
	printf("philo %d\n", id);
	pthread_mutex_unlock(ph->data_mutex);

	return (NULL);
}
