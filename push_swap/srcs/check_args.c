/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:17:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(char **args);

static int	check_limits(char **args);

static int	check_minlimit(char *arg);

static int	check_maxlimit(char *arg);

int	check_args(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '-' || args[i][0] == '+')
			j = 0;
		else
			j = -1;
		if (!args[i][j + 1])
			return (0);
		while (args[i][++j])
			if (!ft_isdigit(args[i][j]))
				return (0);
	}
	if (!check_limits(args))
		return (0);
	if (!check_duplicates(args))
		return (0);
	return (1);
}

static int	check_limits(char **args)
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (args[++i])
	{
		if (args[i][0] == '+')
			ret = check_maxlimit(args[i] + 1);
		else if (ft_isdigit(args[i][0]))
			ret = check_maxlimit(args[i]);
		else if (args[i][0] == '-')
			ret = check_minlimit(args[i] + 1);
		if (ret == 0)
			return (0);
	}
	return (1);
}

static int	check_maxlimit(char *arg)
{
	while (*arg == '0')
		++arg;
	if (ft_strlen(arg) > MAX_INT_STRLEN)
		return (0);
	else if (ft_strlen(arg) == MAX_INT_STRLEN \
			&& ft_strcmp(arg, MAX_INT_STR) > 0)
		return (0);
	return (1);
}

static int	check_minlimit(char *arg)
{
	while (*arg == '0')
		++arg;
	if (ft_strlen(arg) > MIN_INT_STRLEN)
		return (0);
	else if (ft_strlen(arg) == MIN_INT_STRLEN \
			&& ft_strcmp(arg, MIN_INT_STR) > 0)
		return (0);
	return (1);
}

static int	check_duplicates(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = i;
		while (args[++j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
		}
	}
	return (1);
}
