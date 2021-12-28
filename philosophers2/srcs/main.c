/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:37:17 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/28 22:26:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_threads(t_args *args);

static int	join_threads(t_args *args, void **value_ptr);

int	main(int argc, char **argv)
{
	int		ret;
	t_args	args;
	void	**value_ptr;

	ret = init_args(&args, argc, argv);
	if (ret)
		return (ret);
	value_ptr = malloc(sizeof(void *) * args.phs_num);
	if (!value_ptr)
	{
		write(STDERR_FILENO, g_mal_err_mes, sizeof(g_mal_err_mes));
		completion(&args, args.phs_num, 1, 1);
		return (MALLOC_ERROR);
	}
	ret = init_threads(&args);
	if (ret)
		return (ret);
	ret = join_threads(&args, value_ptr);
	free(value_ptr);
	completion(&args, args.phs_num, 1, 1);
	return (ret);
}

static int init_threads(t_args *args)
{	
	int	i;
	int	ret;

	i = 0;
	pthread_mutex_lock(&args->simul);
	while (i < args->phs_num)
	{
		ret = pthread_create(args->ths + i, NULL, thread, &args->phs[i]);
		if (ret)
		{
			write (STDERR_FILENO, g_thr_err_mes, sizeof(g_thr_err_mes));
			completion(args, args->phs_num, 1, 1);
			return (THREAD_ERROR);
		}
		++i;
	}
	gettimeofday(&args->start, NULL);
	pthread_mutex_unlock(&args->simul);
	return (0);
}

/*
static void	check_death(t_arg	*args)
{
	int		i;
	int		num;
	t_ph	*phs;

	i = -1;
	num = args->phs_num;
	phs = args->phs;
	while (++i < num)
	{
		
	}
}
*/

static int	join_threads(t_args *args, void **value_ptr)
{
	int	i;
	int	ret;

	i = 0;
	while (i < args->phs_num)
	{
		ret = pthread_join(args->ths[i], value_ptr + i);
		if (ret || value_ptr[i])
		{
			write(STDERR_FILENO, g_thrj_err_mes, sizeof(g_thrj_err_mes));
			return (JOIN_ERROR);
		}
		++i;
	}
	return (0);
}
