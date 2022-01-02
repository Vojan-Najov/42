/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:59:23 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 19:59:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	completion(t_args *args, int forks_sem, int date_sem, int end_sem)
{
	int	i;
	int	ret;

	i = -1;
	free(args->pids);
	if (date_sem)
	{
		ret = sem_close(args->date_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink("date");
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	if (forks_sem)
	{
		ret = sem_close(args->forks_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink("forks");
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	if (end_sem)
	{
		ret = sem_close(args->end_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink("end");
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	free(args);
}
