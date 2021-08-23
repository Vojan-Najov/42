/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:31:40 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 15:31:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	instruction_apply(t_stacks *stacks, char *line);

static int	is_not_instruction(char *line);

static void	result_print(t_stacks *stacks, char *line);

void	instructions_read(t_stacks *stacks)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	while (ret)
	{
		if (ret == -1)
			exit(EXIT_FAILURE);
		if (is_not_instruction(line))
		{
			write(STDERR_FILENO, ERRMES, ERRMESLEN);
			free(line);
			return ;
		}
		instruction_apply(stacks, line);
		free(line);
		ret = get_next_line(STDIN_FILENO, &line);
	}
	result_print(stacks, line);
}

static void	result_print(t_stacks *stacks, char *line)
{
	if (ft_strcmp(line, ""))
	{
		write(STDERR_FILENO, ERRMES, ERRMESLEN);
		free(line);
		return ;
	}
	free(line);
	if (ft_list_issorted(stacks->a_top) && !stacks->b_top)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

static int	is_not_instruction(char *line)
{
	return (ft_strcmp(line, SWAP_A) && ft_strcmp(line, SWAP_B) && \
	ft_strcmp(line, SWAP_AB) && ft_strcmp(line, PUSH_A) && \
	ft_strcmp(line, PUSH_B) && ft_strcmp(line, ROTATE_A) && \
	ft_strcmp(line, ROTATE_B) && ft_strcmp(line, ROTATE_AB) && \
	ft_strcmp(line, REV_ROTATE_A) && ft_strcmp(line, REV_ROTATE_B) && \
	ft_strcmp(line, REV_ROTATE_AB));
}

static void	instruction_apply(t_stacks *stacks, char *line)
{
	if (ft_strcmp(line, SWAP_A) == 0)
		stack_swap(stacks, STACK_A);
	if (ft_strcmp(line, SWAP_B) == 0)
		stack_swap(stacks, STACK_B);
	if (ft_strcmp(line, SWAP_AB) == 0)
		stack_swap(stacks, STACKS_AB);
	if (ft_strcmp(line, PUSH_A) == 0)
		stack_push(stacks, STACK_A);
	if (ft_strcmp(line, PUSH_B) == 0)
		stack_push(stacks, STACK_B);
	if (ft_strcmp(line, ROTATE_A) == 0)
		stack_rotate(stacks, STACK_A);
	if (ft_strcmp(line, ROTATE_B) == 0)
		stack_rotate(stacks, STACK_B);
	if (ft_strcmp(line, ROTATE_AB) == 0)
		stack_rotate(stacks, STACKS_AB);
	if (ft_strcmp(line, REV_ROTATE_A) == 0)
		stack_rev_rotate(stacks, STACK_A);
	if (ft_strcmp(line, REV_ROTATE_B) == 0)
		stack_rev_rotate(stacks, STACK_B);
	if (ft_strcmp(line, REV_ROTATE_AB) == 0)
		stack_rev_rotate(stacks, STACKS_AB);
}
