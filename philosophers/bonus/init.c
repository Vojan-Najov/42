/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:59:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/06 17:22:33 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_pids(t_args *args);

static int	init_semaphores(t_args *args);

static int	init_sem(sem_t **sem, const char *name, int n, t_args *args);

static int	init_start_simulation(t_args *args);

int	init_args(t_args *args, int argc, char **argv)
{
	int	ret;

	memset(args, 0, sizeof(t_args));
	args->ecount = -1;
	ret = check_args(args, argc, argv);
	if (ret)
	{
		free(args);
		write(STDERR_FILENO, g_arg_err_mes, sizeof(g_arg_err_mes));
		write(STDIN_FILENO, g_help_mes, sizeof(g_help_mes));
		return (ARGS_ERROR);
	}
	ret = init_pids(args);
	if (ret)
		return (ret);
	ret = init_semaphores(args);
	if (ret)
		return (ret);
	ret = init_start_simulation(args);
	if (ret)
		return (ret);
	return (0);
}

static int	init_pids(t_args *args)
{
	args->pids = (pid_t *) malloc(sizeof(pid_t) * args->phs_num);
	if (!args->pids)
	{
		write(STDERR_FILENO, g_mal_err_mes, sizeof(g_mal_err_mes));
		free(args);
		return (MALLOC_ERROR);
	}
	return (0);
}

static int	init_start_simulation(t_args *args)
{
	int	ret;

	ret = gettimeofday(&args->start, NULL);
	if (ret)
	{
		completion(args);
		write(STDERR_FILENO, g_gettime_err_mes, sizeof(g_gettime_err_mes));
		return (GETTIME_ERROR);
	}
	return (0);
}

static int	init_semaphores(t_args *args)
{
	int	ret;

	if (args->ecount > 0)
	{
		ret = init_sem(&args->eaters_sem, EATERS_SEM, 0, args);
		if (ret)
			return (ret);
	}
	ret = init_sem(&args->forks_sem, FORKS_SEM, args->phs_num, args);
	if (ret)
		return (ret);
	ret = init_sem(&args->date_sem, DATE_SEM, 1, args);
	if (ret)
		return (ret);
	ret = init_sem(&args->end_sem, END_SEM, 0, args);
	if (ret)
		return (ret);
	return (0);
}

static int	init_sem(sem_t **sem, const char *name, int n, t_args *args)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, n);
	if (*sem == SEM_FAILED)
	{
		write(STDERR_FILENO, g_sem_open_mes, sizeof(g_sem_open_mes));
		completion(args);
		return (SEMAPHORE_ERROR);
	}
	return (0);
}
