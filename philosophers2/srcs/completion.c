/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:50:06 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/28 21:03:33 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	completion(t_args *args, int forks_num, int date_mutex, int simul_mutex)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < forks_num)
	{
		ret = pthread_mutex_destroy(args->forks + i);
		if (ret)
			write(STDERR_FILENO, g_mutd_err_mes, sizeof(g_mutd_err_mes));
	}
	if (date_mutex)
	{
		ret = pthread_mutex_destroy(&args->date_mutex);
		if (ret)
			write(STDERR_FILENO, g_mutd_err_mes, sizeof(g_mutd_err_mes));
	}
	if (simul_mutex)
	{
		ret = pthread_mutex_destroy(&args->simul);
		if (ret)
			write(STDERR_FILENO, g_mutd_err_mes, sizeof(g_mutd_err_mes));
	}
	free(args->phs);
	free(args->forks);
	free(args->ths);
}
