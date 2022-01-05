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
	int	ret;

	free(args->pids);
	if (date_sem)
	{
		ret = sem_close(args->date_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink(DATE_SEM);
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	if (forks_sem)
	{
		ret = sem_close(args->forks_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink(FORKS_SEM);
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	if (end_sem)
	{
		ret = sem_close(args->end_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink(END_SEM);
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	if (args->ecount > 0 && args->eaters_sem != SEM_FAILED)
	{
		printf("close eatrs_sem______________________\n");
		ret = sem_close(args->eaters_sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink(EATERS_SEM);
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
	free(args);
}
