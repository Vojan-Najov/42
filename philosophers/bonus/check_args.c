/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:50 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/06 19:19:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(char *arg);

int	check_args(t_args *args, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (!check_arg(argv[1]))
		return (1);
	args->phs_num = ft_atoi(argv[1]);
	if (!check_arg(argv[2]))
		return (1);
	args->dtime = ft_atoi(argv[2]) * 1000;
	if (!check_arg(argv[3]))
		return (1);
	args->etime = ft_atoi(argv[3]) * 1000;
	if (!check_arg(argv[4]))
		return (1);
	args->stime = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
	{
		if (!check_arg(argv[5]))
			return (1);
		args->ecount = ft_atoi(argv[5]);
	}
	return (0);
}

static int	check_arg(char *arg)
{
	if (*arg == '+')
		++arg;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		++arg;
	}
	return (1);
}
