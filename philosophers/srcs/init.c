/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:29:37 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/02 18:30:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fields(t_args *args);

static int init_forks (t_args *args);

static void init_philosophers(t_ph *phs, pthread_mutex_t *forks, \
								int phs_num, t_args *args);

static int	init_date_mutex(t_args *args);

int	init_args(t_args *args, int argc, char **argv)
{
	int	ret;

	args->ecount = -1;
	args->phs = NULL;
	args->forks = NULL;
	args->ths = NULL;
	args->simulation = 1;
	ret = check_args(args, argc, argv);
	if (ret)
	{
		write(STDERR_FILENO, g_arg_err_mes, sizeof(g_arg_err_mes));
		write(STDIN_FILENO, g_help_mes, sizeof(g_help_mes));
		return (ARGS_ERROR);
	}
	ret = init_fields(args);
	if (ret)
		return (ret);
	ret = init_forks(args);
	if (ret)
		return (ret);
	init_philosophers(args->phs, args->forks, args->phs_num, args);
	ret = init_date_mutex(args);
	if (ret)
		return (ret);
	return (0);
}

static int	init_fields(t_args *args)
{
	int	num;

	num = args->phs_num;
	args->eaters = 0;
	args->phs = (t_ph *) malloc(sizeof(t_ph) * num);
	args->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * num);
	args->ths = (pthread_t *) malloc(sizeof(pthread_t) * num);
	if (!args->phs || !args->forks || !args->ths)
	{
		write(STDERR_FILENO, g_mal_err_mes, sizeof(g_mal_err_mes));
		completion(args, 0, 0);
		return (MALLOC_ERROR);
	}
	return (0);
}

static int	init_forks (t_args *args)
{
	pthread_mutex_t	*forks;
	int				phs_num;
	int				i;
	int				ret;

	i = 0;
	forks = args->forks;
	phs_num = args->phs_num;
	while (i < phs_num)
	{
		ret = pthread_mutex_init(forks + i, NULL);
		if (ret)
		{
			write(STDERR_FILENO, g_mut_err_mes, sizeof(g_mut_err_mes));
			completion(args, i, 0);
			return (MUTEX_ERROR);
		}
		++i;
	}
	return (0);
}

static void init_philosophers(t_ph *phs, pthread_mutex_t *forks, \
								int phs_num, t_args *args)
{
	int	i;
	int idx1;
	int	idx2;

	i = 0;
	while (i < phs_num)
	{
		phs[i].args = args;
		phs[i].eat_count = 0;
		phs[i].id = i + 1;
		phs[i].eating = 0;
		idx1 = i;
		idx2 = (i + 1) % phs_num;
		if (idx1 < idx2)
		{
			phs[i].first_fork = forks + idx1;
			phs[i].second_fork = forks + idx2;
		}
		else
		{
			phs[i].first_fork = forks + idx2;
			phs[i].second_fork = forks + idx1;
		}
		++i;
	}
}

static int	init_date_mutex(t_args *args)
{
	int	ret;

	ret = pthread_mutex_init(&args->date_mutex, NULL);
	if (ret)
	{
		write(STDERR_FILENO, g_mut_err_mes, sizeof(g_mut_err_mes));
		completion(args, args->phs_num, 0);
		return (MUTEX_ERROR);
	}
	return (0);
}
