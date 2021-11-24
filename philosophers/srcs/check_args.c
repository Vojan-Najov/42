/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:50 by ccartman          #+#    #+#             */
/*   Updated: 2021/11/24 14:42:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(char *arg);

int	check_args(t_args *args, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);   //print info mess
	if (!check_arg(argv[1]))
		return (0);
	args->phs_num = ft_atoi(argv[1]);
	if (!check_arg(argv[2]))
		return (0);
	args->dtime = ft_atoi(argv[2]);
	if (!check_arg(argv[3]))
		return (0);
	args->etime = ft_atoi(argv[3]);
	if (!check_arg(argv[4]))
		return (0);
	args->stime = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!check_arg(argv[5]))
			return (0);
		args->ecount = ft_atoi(argv[5]);
	}
	return (1);
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
