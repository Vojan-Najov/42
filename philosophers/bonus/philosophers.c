/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:50:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 20:05:44 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	launch_philos(t_args *args);

static int	wait_philos(t_args *args, int num);

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
	ret = launch_philos(args);
	if (ret)
		return (ret);
	ret = wait_philos(args, args->phs_num);
	completion(args, 1, 1, 1);
	return (ret);
}

static int	launch_philos(t_args *args)
{
	int	ret;
	int	i;

	ret = gettimeofday(&args->start, NULL);
	if (ret)
	{
		completion(args, 1, 1, 1);
		return (GETTIME_ERROR);
	}
	i = -1;
	while (++i < args->phs_num)
	{
		args->id = i + 1;
		args->pids[i] = fork();
		if (args->pids[i] == -1)
		{
			sem_post(args->end_sem);
			wait_philos(args, i);
			completion(args, 1, 1, 1);
			return (FORK_ERROR);
		}
		else if (args->pids[i] == 0)
		{
			ret = philosopher(args);
			completion(args, 1, 1, 1);
			exit(ret);
		}
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
		sem_wait(args->eaters_sem);
		++i;
	}
	sem_wait(args->date_sem);
	sem_post(args->end_sem);
	return (NULL);
}

static int	wait_philos(t_args *args, int num)
{
	int			i;
	int			ret;
	pthread_t	eat_counter;

	ret = pthread_create(&eat_counter, NULL, eat_count, args);
	if (ret)
	{
		write(STDERR_FILENO, g_thr_err_mes, sizeof(g_thr_err_mes));
		return (THREAD_ERROR);
	}
	ret = pthread_detach(eat_counter);
	if (ret)
	{
		write(STDERR_FILENO, g_thr_err_mes, sizeof(g_thr_err_mes));
		return (THREAD_ERROR);
	}
	sem_wait(args->end_sem);
	i = -1;
	while (++i < num)
		kill(args->pids[i], SIGINT);
	i = -1;
	while (++i < args->phs_num)
		waitpid(-1, &ret, WUNTRACED);

	return (0);
}
