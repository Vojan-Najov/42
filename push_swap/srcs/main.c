/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:21:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 16:54:19 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stacks_init(t_stacks **stacks, char **args, int flag);

static void	stacks_free(t_stacks *stacks, char **args, int flag);

static void	instructions_print(t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;
	int			free_args;

	stacks = NULL;
	free_args = 0;
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
	stacks_init(&stacks, args, free_args);
	if (!ft_list_issorted(stacks->a_top))
		stack_sort(stacks);
	instructions_print(stacks);
	stacks_free(stacks, args, free_args);
	return (0);
}

static void	stacks_init(t_stacks **stacks, char **args, int flag)
{
	int	num;

	*stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!*stacks || !args)
		exit(EXIT_FAILURE);
	(*stacks)->instructions = (char *) ft_calloc(1, 1);
	if (!(*stacks)->instructions)
	{
		stacks_free(*stacks, args, flag);
		exit(EXIT_FAILURE);
	}
	while (*args)
	{
		num = ft_atoi(*args);
		ft_list_push_back(&(*stacks)->a_top, num);
		++args;
	}
	(*stacks)->a_end = ft_list_last((*stacks)->a_top);
}

static void	instructions_print(t_stacks *stacks)
{
	int	len;
	int	ret;

	len = ft_strlen(stacks->instructions);
	ret = write(STDOUT_FILENO, stacks->instructions, len);
	if (ret != len)
		exit(EXIT_FAILURE);
}

static void	stacks_free(t_stacks *stacks, char **args, int flag)
{
	int	i;

	if (stacks)
	{
		ft_list_clear(stacks->a_top);
		ft_list_clear(stacks->b_top);
		ft_list_clear(stacks->frame);
		free(stacks->instructions);
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
