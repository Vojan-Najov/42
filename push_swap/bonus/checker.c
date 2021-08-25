/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:31:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 15:31:18 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	stacks_init(t_stacks **stacks, char **args);

static void	stacks_free(t_stacks *stacks, char **args, int flag);

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;
	int			free_args;

	stacks = NULL;
	free_args = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		free_args = 1;
	}
	else
		args = argv + 1;
	if (!check_args(args))
	{
		write(STDERR_FILENO, ERRMES, ERRMESLEN);
		stacks_free(stacks, args, free_args);
		return (1);
	}
	stacks_init(&stacks, args);
	instructions_read(stacks);
	stacks_free(stacks, args, free_args);
	return (0);
}		

static void	stacks_init(t_stacks **stacks, char **args)
{
	int	num;

	*stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!*stacks || !args)
		exit(EXIT_FAILURE);
	while (*args)
	{
		num = ft_atoi(*args);
		ft_list_push_back(&(*stacks)->a_top, num);
		++args;
	}
	(*stacks)->a_end = ft_list_last((*stacks)->a_top);
}

static void	stacks_free(t_stacks *stacks, char **args, int flag)
{
	int	i;

	if (stacks)
	{
		ft_list_clear(stacks->a_top);
		ft_list_clear(stacks->b_top);
		free(stacks);
	}
	if (flag)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			++i;
		}
		free(args);
	}
}
