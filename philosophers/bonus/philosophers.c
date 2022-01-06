/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:50:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/06 20:53:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	launch_philos(t_args *args);

static int	wait_philos(t_args *args, int num);

static int	launch_eat_counter(t_args *args);

static void	*eat_count(void *vargs);

int	main(int argc, char **argv)
{
	int		ret;
	t_args	*args;

	args = (t_args *) malloc(sizeof(t_args));
	if (!args)
	{
		write(STDERR_FILENO, g_mal_err_mes, sizeof(g_mal_err_mes));
		return (MALLOC_ERROR);
	}
	ret = init_args(args, argc, argv);
	if (ret)
		return (ret);
	if (!args->ecount)
	{
		completion(args);
		return (0);
	}
	ret = launch_philos(args);
	if (ret)
		return (ret);
	ret = launch_eat_counter(args);
	if (ret)
		return (ret);
	ret = wait_philos(args, args->phs_num);
	return (ret);
}

static int	launch_philos(t_args *args)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < args->phs_num)
	{
		args->id = i + 1;
		args->pids[i] = fork();
		if (args->pids[i] == -1)
		{
			sem_post(args->end_sem);
			wait_philos(args, i);
			write(STDERR_FILENO, g_fork_err_mes, sizeof(g_fork_err_mes));
			return (FORK_ERROR);
		}
		else if (args->pids[i] == 0)
		{
			ret = philosopher(args);
			completion(args);
			exit(ret);
		}
	}
	return (0);
}

static int	launch_eat_counter(t_args *args)
{
	int			ret;
	pthread_t	eat_counter;

	if (args->ecount <= 0)
		return (0);
	ret = pthread_create(&eat_counter, NULL, eat_count, args);
	if (ret)
	{
		sem_post(args->end_sem);
		wait_philos(args, args->phs_num);
		write(STDERR_FILENO, g_thr_err_mes, sizeof(g_thr_err_mes));
		return (THREAD_ERROR);
	}
	ret = pthread_detach(eat_counter);
	if (ret)
	{
		sem_post(args->end_sem);
		wait_philos(args, args->phs_num);
		write(STDERR_FILENO, g_dtch_err_mes, sizeof(g_dtch_err_mes));
		return (DETACH_ERROR);
	}
	return (0);
}

static void	*eat_count(void *vargs)
{
	t_args	*args;
	int		i;

	args = (t_args *) vargs;
	i = 0;
	while (i < args->phs_num)
	{
		++i;
		sem_wait(args->eaters_sem);
		if (i < args->phs_num)
			sem_post(args->date_sem);
	}
	sem_post(args->end_sem);
	return (NULL);
}

static int	wait_philos(t_args *args, int num)
{
	int			i;
	int			ret;

	sem_wait(args->end_sem);
	i = -1;
	while (++i < num)
		kill(args->pids[i], SIGINT);
	i = -1;
	while (++i < args->phs_num)
		waitpid(-1, &ret, WUNTRACED);
	if (args->ecount > 0)
	{
		i = -1;
		while (++i < args->phs_num)
			sem_post(args->eaters_sem);
		sem_post(args->date_sem);
	}
	completion(args);
	return (0);
}
