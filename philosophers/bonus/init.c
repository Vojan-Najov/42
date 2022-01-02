/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:59:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 20:08:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_semaphores(t_args *args);

int	init_args(t_args *args, int argc, char **argv)
{
	int	ret;

	memset(args, 0, sizeof(t_args));
	args->ecount = -1;
	ret = check_args(args, argc, argv);
	if (ret)
	{
		write(STDERR_FILENO, g_arg_err_mes, sizeof(g_arg_err_mes));
		write(STDIN_FILENO, g_help_mes, sizeof(g_help_mes));
		return (ARGS_ERROR);
	}
	args->pids = (pid_t *) malloc(sizeof(pid_t) * args->phs_num);
	if (!args->pids)
	{
		write(STDERR_FILENO, g_mal_err_mes, sizeof(g_mal_err_mes));
		free(args);
		return (MALLOC_ERROR);
	}
	ret = init_semaphores(args);
	if (ret)
		return (ret);
	return (0);
}

static int	init_semaphores(t_args *args)
{
	args->forks_sem = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, args->phs_num);
	if (args->forks_sem == SEM_FAILED)
	{
		write(STDERR_FILENO, g_sem_open_mes, sizeof(g_sem_open_mes));
		completion(args, 0, 0, 0);
		return (SEMAPHORE_ERROR);
	}
	args->date_sem = sem_open("date", O_CREAT | O_EXCL, S_IWUSR, 1);
	if (args->date_sem == SEM_FAILED)
	{
		write(STDERR_FILENO, g_sem_open_mes, sizeof(g_sem_open_mes));
		completion(args, 1, 0, 0);
		return (SEMAPHORE_ERROR);
	}
	args->end_sem = sem_open("end", O_CREAT | O_EXCL, S_IWUSR, 0);
	if (args->end_sem == SEM_FAILED)
	{
		write(STDERR_FILENO, g_sem_open_mes, sizeof(g_sem_open_mes));
		completion(args, 1, 1, 0);
		return (SEMAPHORE_ERROR);
	}
	return (0);
}
