/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:59:23 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/06 19:19:40 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_sem_close(sem_t *sem, const char *name);

void	completion(t_args *args)
{
	free(args->pids);
	ft_sem_close(args->forks_sem, FORKS_SEM);
	ft_sem_close(args->eaters_sem, EATERS_SEM);
	ft_sem_close(args->date_sem, DATE_SEM);
	ft_sem_close(args->end_sem, END_SEM);
	free(args);
}

static void	ft_sem_close(sem_t *sem, const char *name)
{
	int	ret;

	if (sem != SEM_FAILED && sem != NULL)
	{
		ret = sem_close(sem);
		if (ret)
			write(STDERR_FILENO, g_sem_close_mes, sizeof(g_sem_close_mes));
		ret = sem_unlink(name);
		if (ret)
			write(STDERR_FILENO, g_sem_unl_mes, sizeof(g_sem_unl_mes));
	}
}
